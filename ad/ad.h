#ifndef HAD_H__
#define HAD_H__
#ifdef _WIN32
#define threadDefine thread_local
#endif
#ifdef __unix
#define USE_AATREE
#define threadDefine __thread
#endif

#include <vector>
#include <cmath>
#include <algorithm>

#ifndef M_PI
#define M_PI std::acos(-1)
#endif
template <typename S>
S normcdf(S in)
{
    return 0.5*(1+std::erf(in/std::sqrt(2.)));
}

template <typename S>
S pdf(S in)
{
    return std::exp(-in*in*0.5)/std::sqrt(2*M_PI);
}

template <typename S>
S dpdf(S in)
{
    return -in*std::exp(-in*in*0.5)/std::sqrt(2*M_PI);
}

namespace ad {

// Change the following line if you want to use single precision floats
    typedef double real;
    typedef double* RealArray;
    typedef unsigned int VertexId;

    struct ADGraph;
    struct areal;

    extern threadDefine ADGraph* g_ADGraph;
// Declare this in your .cpp source
#define DECLARE_ADGRAPH() namespace ad { threadDefine ADGraph* g_ADGraph = 0; }

    areal NewAReal(const real val);

    struct areal {
        areal() {}

        areal(const real val) {
            *this = NewAReal(val);
        }

        areal(const real val, const VertexId varId) :
                val(val), varId(varId) {}

        real val;
        VertexId varId;
    };

    struct ADEdge {
        ADEdge() {}
        ADEdge(const VertexId to, const real w = real(0.0)) :
                to(to), w(w) {}

        VertexId to;
        real w;
    };

// We assume there is at most 2 outgoing edges from this vertex
    struct ADVertex {
        ADVertex(const VertexId newId) {
            e1 = e2 = ADEdge(newId);
            w = soW = real(0.0);
        }

        // If ei.to == the id of this vertex, then the edge does not exist
        ADEdge e1, e2;
        // first-order weight
        real w;
        // second-order weights
        // for vertex with single outgoing edge,
        // soW represents the second-order weight of the conntecting vertex (d^2f/dx^2)
        // for vertex with two outgoing edges,
        // soW represents the second-order weight between the conntecting vertices (d^2f/dxdy)
        // the system assumes d^2f/dx^2 & d^2f/dy^2 are both zero in the two outgoing edges case to save memory
        real soW;
    };

    struct BTNode {
        BTNode() {}
        BTNode(const VertexId key, const real val) : key(key), val(val) {
            left = right = - 1;
#ifdef USE_AATREE
            level = 1;
#endif
        }

        VertexId key;
        real val;
        int left;
        int right;
#ifdef USE_AATREE
        int level;
#endif
    };

    struct BTree {
        BTree() {
            nodes.reserve(32);
            root = 0;
        }
#ifdef USE_AATREE
        inline void Skew() {
            if (nodes.size() == 0 ||
                nodes[root].left == -1) {
                return;
            }
            while (nodes[nodes[root].left].level == nodes[root].level) {
                int l = nodes[root].left;
                nodes[root].left = nodes[l].right;
                nodes[l].right = root;
                root = l;
            }
        }

        inline void Split() {
            if (nodes.size() == 0 ||
                nodes[root].right == -1 ||
                nodes[nodes[root].right].right == -1) {
                return;
            }
            while (nodes[root].level == nodes[nodes[nodes[root].right].right].level) {
                int r = nodes[root].right;
                nodes[root].right = nodes[r].left;
                nodes[r].left = root;
                nodes[r].level++;
                root = r;
            }
        }
#endif
        inline void Insert(const VertexId key, const real val) {
            int index = root;
            if (nodes.size() > 0) {
                int *lastEdge;
                do {
                    if (key == nodes[index].key) {
                        nodes[index].val += val;
                        return;
                    }
                    lastEdge = &(nodes[index].left) + (key > nodes[index].key);
                    index = *lastEdge;
                } while (index >= 0);

                *lastEdge =(int) nodes.size();
            }
            nodes.push_back(BTNode(key, val));
#ifdef USE_AATREE
            Skew();
            Split();
#endif
        }

        inline real Query(const VertexId key) {
            int index = root;
            while (index >= 0 && index < (int)nodes.size()) {
                if (key == nodes[index].key) {
                    return nodes[index].val;
                } else if (key < nodes[index].key) {
                    index = nodes[index].left;
                } else {
                    index = nodes[index].right;
                }
            }
            return real(0.0);
        }

        inline void Clear() {
            nodes.clear();
            root = 0;
        }

        std::vector<BTNode> nodes;
        int root;
    };

    struct ADGraph {
        ADGraph() {
            g_ADGraph = this;
        }

        inline void Clear() {
            vertices.clear();
            soEdges.clear();
            selfSoEdges.clear();
        }

        std::vector<ADVertex> vertices;
        std::vector<BTree> soEdges;
        std::vector<real> selfSoEdges;
    };

    inline areal NewAReal(const real val) {
        std::vector<ADVertex> &vertices = g_ADGraph->vertices;
        VertexId newId =(int) vertices.size();
        vertices.push_back(ADVertex(newId));
        return areal(val, newId);
    }

    inline void AddEdge(const areal &c, const areal &p,
                        const real w, const real soW) {
        ADVertex &v = g_ADGraph->vertices[c.varId];
        v.e1 = ADEdge(p.varId, w);
        v.soW = soW;
    }
    inline void AddEdge(const areal &c,
                        const areal &p1, const areal &p2,
                        const real w1, const real w2,
                        const real soW) {
        ADVertex &v = g_ADGraph->vertices[c.varId];
        v.e1 = ADEdge(p1.varId, w1);
        v.e2 = ADEdge(p2.varId, w2);
        v.soW = soW;
    }

////////////////////// Addition ///////////////////////////
    inline areal operator+(const areal &l, const areal &r) {
        areal ret = NewAReal(l.val + r.val);
        AddEdge(ret, l, r, real(1.0), real(1.0), real(0.0));
        return ret;
    }
    inline areal operator+(const areal &l, const real r) {
        areal ret = NewAReal(l.val + r);
        AddEdge(ret, l, real(1.0), real(0.0));
        return ret;
    }
    inline areal operator+(const real l, const areal &r) {
        return r + l;
    }
    inline areal& operator+=(areal &l, const areal &r) {
        return (l = l + r);
    }
    inline areal& operator+=(areal &l, const real r) {
        return (l = l + r);
    }
///////////////////////////////////////////////////////////

////////////////// Subtraction ////////////////////////////
    inline areal operator-(const areal &l, const areal &r) {
        areal ret = NewAReal(l.val - r.val);
        AddEdge(ret, l, r, real(1.0), -real(1.0), real(0.0));
        return ret;
    }
    inline areal operator-(const areal &l, const real r) {
        areal ret = NewAReal(l.val - r);
        AddEdge(ret, l, real(1.0), real(0.0));
        return ret;
    }
    inline areal operator-(const real l, const areal &r) {
        areal ret = NewAReal(l - r.val);
        AddEdge(ret, r, real(-1.0), real(0.0));
        return ret;
    }
    inline areal& operator-=(areal &l, const areal &r) {
        return (l = l - r);
    }
    inline areal& operator-=(areal &l, const real r) {
        return (l = l - r);
    }
    inline areal operator-(const areal &x) {
        areal ret = NewAReal(-x.val);
        AddEdge(ret, x, real(-1.0), real(0.0));
        return ret;
    }
///////////////////////////////////////////////////////////

////////////////// Multiplication /////////////////////////
    inline areal operator*(const areal &l, const areal &r) {
        areal ret = NewAReal(l.val * r.val);
        AddEdge(ret, l, r, r.val, l.val, real(1.0));
        return ret;
    }
    inline areal operator*(const areal &l, const real r) {
        areal ret = NewAReal(l.val * r);
        AddEdge(ret, l, r, real(0.0));
        return ret;
    }
    inline areal operator*(const real l, const areal &r) {
        return r * l;
    }
    inline areal& operator*=(areal &l, const areal &r) {
        return (l = l * r);
    }
    inline areal& operator*=(areal &l, const real r) {
        return (l = l * r);
    }
///////////////////////////////////////////////////////////

////////////////// Inversion //////////////////////////////
    inline areal Inv(const areal &x) {
        real invX = real(1.0) / x.val;
        real invXSq = invX * invX;
        real invXCu = invXSq * invX;
        areal ret = NewAReal(invX);
        AddEdge(ret, x, -invXSq, real(2.0) * invXCu);
        return ret;
    }
    inline real Inv(const real x) {
        return real(1.0) / x;
    }
///////////////////////////////////////////////////////////

////////////////// Division ///////////////////////////////
    inline areal operator/(const areal &l, const areal &r) {
        return l * Inv(r);
    }
    inline areal operator/(const areal &l, const real r) {
        return l * Inv(r);
    }
    inline areal operator/(const real l, const areal &r) {
        return l * Inv(r);
    }
    inline areal& operator/=(areal &l, const areal &r) {
        return (l = l / r);
    }
    inline areal& operator/=(areal &l, const real r) {
        return (l = l / r);
    }
///////////////////////////////////////////////////////////

////////////////// Comparisons ////////////////////////////
    inline bool operator<(const areal &l, const areal &r) {
        return l.val < r.val;
    }
    inline bool operator<=(const areal &l, const areal &r) {
        return l.val <= r.val;
    }
    inline bool operator>(const areal &l, const areal &r) {
        return l.val > r.val;
    }
    inline bool operator>=(const areal &l, const areal &r) {
        return l.val >= r.val;
    }
    inline bool operator==(const areal &l, const areal &r) {
        return l.val == r.val;
    }
///////////////////////////////////////////////////////////

//////////////// Misc functions ///////////////////////////
    inline real square(const real x) {
        return x * x;
    }
    inline areal square(const areal &x) {
        real sqX = x.val * x.val;
        areal ret = NewAReal(sqX);
        AddEdge(ret, x, real(2.0) * x.val, real(0.0));
        return ret;
    }
    inline areal sqrt(const areal &x) {
        real sqrtX = std::sqrt(x.val);
        real invSqrtX = real(1.0) / sqrtX;
        areal ret = NewAReal(sqrtX);
        AddEdge(ret, x, real(0.5) * invSqrtX, - real(0.25) * invSqrtX / x.val);
        return ret;
    }
    inline areal pow(const areal &x, const real a) {
        real powX = std::pow(x.val, a);
        areal ret = NewAReal(powX);
        AddEdge(ret, x, a * std::pow(x.val, a - real(1.0)),
                a * (a - real(1.0)) * std::pow(x.val, a - real(2.0)));
        return ret;
    }
    inline areal exp(const areal &x) {
        real expX = std::exp(x.val);
        areal ret = NewAReal(expX);
        AddEdge(ret, x, expX, expX);
        return ret;
    }
    inline areal log(const areal &x) {
        real logX = std::log(x.val);
        areal ret = NewAReal(logX);
        real invX = real(1.0) / x.val;
        AddEdge(ret, x, invX, - invX * invX);
        return ret;
    }
    inline areal sin(const areal &x) {
        real sinX = std::sin(x.val);
        areal ret = NewAReal(sinX);
        AddEdge(ret, x, std::cos(x.val), -sinX);
        return ret;
    }
    inline areal cos(const areal &x) {
        real cosX = std::cos(x.val);
        areal ret = NewAReal(cosX);
        AddEdge(ret, x, -std::sin(x.val), -cosX);
        return ret;
    }
    inline areal tan(const areal &x) {
        real tanX = std::tan(x.val);
        real secX = real(1.0) / std::cos(x.val);
        real sec2X = secX * secX;
        areal ret = NewAReal(tanX);
        AddEdge(ret, x, sec2X, real(2.0) * tanX * sec2X);
        return ret;
    }
    inline areal asin(const areal &x) {
        real asinX = std::asin(x.val);
        areal ret = NewAReal(asinX);
        real tmp = real(1.0) / (real(1.0) - x.val * x.val);
        real sqrtTmp = std::sqrt(tmp);
        AddEdge(ret, x, sqrtTmp, x.val * sqrtTmp * tmp);
        return ret;
    }
    inline areal acos(const areal &x) {
        real acosX = std::acos(x.val);
        areal ret = NewAReal(acosX);
        real tmp = real(1.0) / (real(1.0) - x.val * x.val);
        real negSqrtTmp = -std::sqrt(tmp);
        AddEdge(ret, x, negSqrtTmp, x.val * negSqrtTmp * tmp);
        return ret;
    }

    ////My Functions
    inline areal cdf(const areal &x) {
        real erfX = normcdf(x.val);
        areal ret = NewAReal(erfX);
        real der=pdf(x.val);
        AddEdge(ret, x, der, -der*x.val);
        return ret;
    }

    inline areal cosh(const areal &x) {
        real erfX = std::cosh(x.val);
        areal ret = NewAReal(erfX);
        real der=std::sinh(x.val);
        AddEdge(ret, x, der,x.val);
        return ret;
    }

    inline areal sinh(const areal &x) {
        real erfX = std::sinh(x.val);
        areal ret = NewAReal(erfX);
        real der=std::cosh(x.val);
        AddEdge(ret, x, der,x.val);
        return ret;
    }

    inline areal atan(const areal &x) {
        real erfX = std::atan(x.val);
        areal ret = NewAReal(erfX);
        real der=1./(1.+x.val*x.val);
        AddEdge(ret, x,der, -der*der*2.*x.val);
        return ret;
    }

///////////////////////////////////////////////////////////

    inline void SetAdjoint(const areal &v, const real adj) {
        g_ADGraph->vertices[v.varId].w = adj;
    }

    inline real GetAdjoint(const areal &v) {
        return g_ADGraph->vertices[v.varId].w;
    }

    inline real GetAdjoint(const areal &i, const areal &j) {
        if (i.varId == j.varId) {
            return g_ADGraph->selfSoEdges[i.varId];
        } else {
            return g_ADGraph->soEdges[std::max(i.varId, j.varId)].Query(std::min(i.varId, j.varId));
        }
    }

    inline std::vector<real> getGradient(const std::vector<areal> &v,int N)
    {
        std::vector<real> outVec=std::vector<real>(N);
        for(int i=0;i<N;i++)
            outVec[i]=GetAdjoint(v[i]);
        return outVec;
    }

    inline VertexId SingleEdgePropagate(VertexId x, real &a) {
        bool cont = g_ADGraph->vertices[x].e1.to != x &&
                    g_ADGraph->vertices[x].e2.to == x;
        while (cont) {
            a *= g_ADGraph->vertices[x].e1.w;
            x = g_ADGraph->vertices[x].e1.to;
            cont = g_ADGraph->vertices[x].e1.to != x &&
                   g_ADGraph->vertices[x].e2.to == x;
        }
        return x;
    }

    inline void PushEdge(const ADEdge &foEdge, const ADEdge &soEdge) {
        if (foEdge.to == soEdge.to) {
            g_ADGraph->selfSoEdges[foEdge.to] += real(2.0) * foEdge.w * soEdge.w;
        } else {
            g_ADGraph->soEdges[std::max(foEdge.to, soEdge.to)].Insert(
                    std::min(foEdge.to, soEdge.to), foEdge.w * soEdge.w);
        }
    }

    inline void PropagateAdjoint() {
        if (g_ADGraph->vertices.size() > g_ADGraph->soEdges.size()) {
            g_ADGraph->soEdges.resize(g_ADGraph->vertices.size());
        } else {
            for (int i = 0; i < (int)g_ADGraph->soEdges.size(); i++) {
                g_ADGraph->soEdges[i].Clear();
            }
        }
        g_ADGraph->selfSoEdges.resize(g_ADGraph->vertices.size(), real(0.0));
        // Any chance for SSE/AVX parallism?

        for (VertexId vid =(int) g_ADGraph->vertices.size() - 1; vid > 0; vid--) {
            ADVertex &vertex = g_ADGraph->vertices[vid];
            ADEdge &e1 = vertex.e1;
            ADEdge &e2 = vertex.e2;
            if (e1.to == vid) {
                continue;
            }

            // Pushing
            BTree &btree = g_ADGraph->soEdges[vid];
            std::vector<BTNode>::iterator it;
            if (e2.to == vid) {
                for (it = btree.nodes.begin(); it != btree.nodes.end(); it++) {
                    ADEdge soEdge(it->key, it->val);
                    PushEdge(e1, soEdge);
                }
            } else {
                for (it = btree.nodes.begin(); it != btree.nodes.end(); it++) {
                    ADEdge soEdge(it->key, it->val);
                    PushEdge(e1, soEdge);
                    PushEdge(e2, soEdge);
                }
            }
            if (g_ADGraph->selfSoEdges[vid] != real(0.0)) {
                g_ADGraph->selfSoEdges[e1.to] += e1.w * e1.w * g_ADGraph->selfSoEdges[vid];
                if (e2.to != vid) {
                    g_ADGraph->selfSoEdges[e2.to] += e2.w * e2.w * g_ADGraph->selfSoEdges[vid];
                    if (e1.to == e2.to) {
                        g_ADGraph->selfSoEdges[e2.to] += real(2.0) * e1.w * e2.w * g_ADGraph->selfSoEdges[vid];
                    } else {
                        g_ADGraph->soEdges[std::max(e1.to, e2.to)].Insert(std::min(e1.to, e2.to),
                                                                          e1.w * e2.w * g_ADGraph->selfSoEdges[vid]);
                    }
                }
            }

            // release memory?

            real a = vertex.w;
            if (a != real(0.0)) {
                // Creating
                if (vertex.soW != real(0.0)) {
                    if (e2.to == vid) { // single-edge
                        g_ADGraph->selfSoEdges[e1.to] += a * vertex.soW;
                    } else if (e1.to == e2.to) {
                        g_ADGraph->selfSoEdges[e1.to] += real(2.0) * a * vertex.soW;
                    } else {
                        g_ADGraph->soEdges[std::max(e1.to, e2.to)].Insert(std::min(e1.to, e2.to),
                                                                          a * vertex.soW);
                    }
                }
                // Adjoint
                vertex.w = real(0.0);
                g_ADGraph->vertices[e1.to].w += a * e1.w;
                if (e2.to != vid) {
                    g_ADGraph->vertices[e2.to].w += a * e2.w;
                }
            }
        }
    }
} //namespace ad


#endif // HAD_H__
