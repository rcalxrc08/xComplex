//
// Created by nico on 1/25/17.
//

#ifndef TESI_ACOMPLEX_H
#define TESI_ACOMPLEX_H
#include <cmath>
#include <vector>
#include "adatan2.h"
#include "dcomplex.h"
#define ImagUnit "j"
//// All is passed by reference
class dcomplex;

#ifdef USE_ADDICT
using namespace ad;
#endif

class acomplex
{
private:
    AReal re;
    AReal im;
public:
    explicit acomplex () {}
    explicit acomplex (const AReal& RealP,const AReal& im) :re(RealP),im(im){}

////IntraClass Operators
    AReal getReal() const {return re;}

    AReal getImm() const {return im;}

    AReal getRho() const {using namespace std; return sqrt(re*re+im*im);}

    AReal getTheta() const {using namespace std; return atan2(im, re);}

    AReal getNormSqr() const {return re*re+im*im;}

    friend std::ostream& operator<<(std::ostream& os, acomplex& obj)
    {
        AReal tmpIM=(-1.0*obj.getImm());
        Real tmp1=LVAL tmpIM RVAL;
        Real re=LVAL obj.getReal() RVAL;
        Real im=LVAL obj.getImm() RVAL;
        if(obj.getImm()>=0.0)
            os<<re<<" + "<<ImagUnit<<" "<<im;
        else
            os<<re<<" - "<<ImagUnit<<" "<<(tmp1);

        return os;
    }
////InterClass Operators
    bool operator==(acomplex& o)
    {
        return (im==o.getImm()&&re==o.getReal());
    }

    bool operator!=(acomplex& o)
    {
        return !((*this)==o);
    }

////acomplex op AReal
    inline acomplex operator+(const AReal& arealNum) //Adouble SUM
    const {
        return acomplex(re+arealNum,im);
    }

    inline acomplex operator-(const AReal& arealNum)
    const{
        return acomplex(re-arealNum,im);
    }

    inline acomplex operator*(const AReal& arealNum)
    const{
        return acomplex(re*arealNum,im*arealNum);
    }

    inline acomplex operator/(const AReal& arealNum)
    const{
        return acomplex(re/arealNum,im/arealNum);
    }

    ////op=
    inline acomplex operator+=(const AReal& arealNum) //Double SUM
    const {
        return (*this)+arealNum;
    }

    inline acomplex operator-=(const AReal& arealNum)
    const{
        return (*this)-arealNum;
    }

    inline acomplex operator*=(const AReal& arealNum)
    const{
        return (*this)*arealNum;
    }

    inline acomplex operator/=(const AReal& arealNum)
    const{
        return (*this)/arealNum;
    }

    ////Acomplex op Real
    inline acomplex operator+(const Real& realNum) //Double SUM
    const {
        return acomplex(re+realNum,im);
    }

    inline acomplex operator-(const Real& realNum)
    const{
        return acomplex(re-realNum,im);
    }

    inline acomplex operator*(const Real& realNum)
    const{
        return acomplex(re*realNum,im*realNum);
    }

    inline acomplex operator/(const Real& realNum)
    const{
        return acomplex(re/realNum,im/realNum);
    }
    ////op=
    inline acomplex operator+=(const Real& realNum) //Double SUM
    const {
        return (*this)+realNum;
    }

    inline acomplex operator-=(const Real& realNum)
    const{
        return (*this)-realNum;
    }

    inline acomplex operator*=(const Real& realNum)
    const{
        return (*this)*realNum;
    }

    inline acomplex operator/=(const Real& realNum)
    const{
        return (*this)/realNum;
    }



    ////Real op Acomplex
    friend acomplex operator+(Real c,const acomplex& in);
    friend acomplex operator*(Real c,const acomplex& in);
    friend acomplex operator/(Real c,const acomplex& in);
    friend acomplex operator-(Real c,const acomplex& in);
    ////AReal op Acomplex
    friend acomplex operator+(const AReal& arealNum,const acomplex& in);
    friend acomplex operator*(const AReal& arealNum,const acomplex& in);
    friend acomplex operator/(const AReal& arealNum,const acomplex& in);
    friend acomplex operator-(const AReal& arealNum,const acomplex& in);

    ////Acomplex op Acomplex
    inline acomplex operator+(const acomplex& cpx) //Acomplex SUM
    const{
        return acomplex(re + cpx.getReal(),im + cpx.getImm());
    }

    inline acomplex operator-(const acomplex& cpx)
    const{
        return acomplex(re-cpx.getReal(),im-cpx.getImm());;
    }

    inline acomplex operator*(const acomplex& cpx)
    const{
        return acomplex(re*cpx.getReal()-im*cpx.getImm(),im*cpx.getReal()+re*cpx.getImm());
    }

    inline acomplex operator/(const acomplex& cpx)
    const{
        return acomplex((re*cpx.getReal()+im*cpx.getImm())/cpx.getNormSqr(),(im*cpx.getReal()-re*cpx.getImm())/cpx.getNormSqr());
    }

    ////op=
    inline acomplex operator+=(const acomplex& cpx)
    const{
        return (*this)+cpx;
    }

    inline acomplex operator-=(const acomplex& cpx)
    const{
        return (*this)-cpx;
    }

    inline acomplex operator*=(const acomplex& cpx)
    const{
        return (*this)*cpx;
    }

    inline acomplex operator/=(const acomplex& cpx)
    const{
        return (*this)/cpx;
    }

    ////acomplex op dcomplex
    acomplex operator+(const dcomplex& cpx);////ADJ
    acomplex operator-(const dcomplex& cpx);////ADJ
    acomplex operator*(const dcomplex& cpx);////ADJ
    acomplex operator/(const dcomplex& cpx);////ADJ
    ////op=
    acomplex operator+=(const dcomplex& cpx);////ADJ
    acomplex operator-=(const dcomplex& cpx);////ADJ
    acomplex operator*=(const dcomplex& cpx);////ADJ
    acomplex operator/=(const dcomplex& cpx);////ADJ

////Mathematical Operations

    friend acomplex pow(const acomplex& in,const AReal& n)
    {
        using namespace std;
        return acomplex(cos(n*in.getTheta())*pow(in.getRho(),LVAL n RVAL),sin(n*in.getTheta())*pow(in.getRho(),LVAL n RVAL));
    }

    friend acomplex pow(const acomplex& in,const Real& n)
    {
        using namespace std;
        return acomplex(cos(n*in.getTheta())*pow(in.getRho(),n),sin(n*in.getTheta())*pow(in.getRho(),n));
    }

    friend acomplex exp(const acomplex& in)
    {
        using namespace std;
        return acomplex(exp(in.getReal())*cos(in.getImm()),exp(in.getReal())*sin(in.getImm()));
    }

    friend acomplex cos(const acomplex& in)
    {
        using namespace std;
        return acomplex(cosh((in).getImm())*cos((in).getReal()),-1.*sin((in).getReal())*sinh((in).getImm()));
    }

    friend acomplex sin(const acomplex& in)
    {
        using namespace std;
        return acomplex(sin(in.getReal())*cosh(in.getImm()),cos((in).getReal())*sinh((in).getImm()));
    }

    friend acomplex tan(const acomplex& in)
    {
        //TODO Optimize function tangent for acomplex
        using namespace std;
        return sin(in)/cos(in);
    }

    friend acomplex log(const acomplex& in)
    {
        using namespace std;
        return acomplex(log(in.getRho()),in.getTheta());
    }
    friend void swap(acomplex& a, acomplex& b)
    {

        std::swap(a.re, b.re);
        std::swap(a.im, b.im);
    }
};

////acomplex.cpp
////Real op acomplex
inline acomplex operator+(Real realNum,const acomplex& in)
{
    return in+realNum;
}

inline acomplex operator-(Real realNum,const acomplex& in)
{
    return realNum+(-1.*in);
}

inline acomplex operator*(Real realNum,const acomplex& in)
{
    return in*realNum;
}

inline acomplex operator/(Real realNum,const acomplex& in)
{
    return in*(1./realNum);
}
////op=


////AReal op acomplex
inline acomplex operator+(const AReal& arealNum,const acomplex& in)
{
    return in+arealNum;
}
inline acomplex operator-(const AReal& arealNum,const acomplex& in)
{
    return -1.*in+arealNum;
}

inline acomplex operator*(const AReal& arealNum,const acomplex& in)
{
    return in*arealNum;
}

inline acomplex operator/(const AReal& arealNum,const acomplex& in)
{
    return ((AReal)(1./arealNum))*in;
}

#endif //TESI_ACOMPLEX_H
