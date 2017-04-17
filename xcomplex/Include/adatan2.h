//
// Created by nico on 1/18/17.
//

#ifndef TESI_AATAN2_H
#define TESI_AATAN2_H

#include <math.h>
#include <stdexcept>

////TAPESCRIPT LIBRARY
#ifdef CL_TAPE_CPPAD
using namespace std;
#define NAMELIB "Using Tapescript Library"
#include <map>
#include <fstream>
#include <cl/tape/impl/detail/enable_ad.hpp>
#include <cl/tape/util/testoutput.hpp>
#include <cl/tape/tape.hpp>
#define STARTAD double xnameimpossible=0
#define STARTREC(in)  cl::tape_start(in)
#define SETGRAD(in,out) cl::tfunc<double> f(in, out)
#define GETGRAD(in,i) (f.reverse(1, std::vector<double> (1, 1.0)))[i]
#define GETGRADS(in,i) (f.reverse(1, std::vector<double> (1, 1.0)))
typedef cl::tdouble AReal;
#define LVAL (Real)
#define RVAL
#endif
#ifdef USE_ADDICT
#include "ad.h"
#define NAMELIB "Using Addict Library"
using namespace ad;
typedef areal AReal;
#define STARTAD  ADGraph adGraph
#define STARTREC(in) auto pxoieMJbGFUm1=1
#define SETGRAD(in,out)  SetAdjoint(out, 1.0);PropagateAdjoint();
#define GETGRAD(in) GetAdjoint(in)
#define GETGRADS(in,i) for_each( in.begin(), in.end(), [](double ss) { cout << ss; } );
#define LVAL
#define RVAL .val
#endif


////ADEPT LIBRARY
#ifdef USE_ADEPT
#define NAMELIB "Using Adept 1.0 Library"
#include "adept.h"
#define STARTAD adept::Stack s1
#define STARTREC(in) s1.new_recording()
#define SETGRAD(in,out) out.set_gradient(1.0);s1.reverse()
#define GETGRAD(in) (in.get_gradient())
#define GETGRADS(in,i) for_each( in.begin(), in.end(), [](double ss) { cout << ss; } );
typedef adept::adouble AReal;
#define LVAL
#define RVAL .value()
#endif

////ADEPT 2.0 LIBRARY
#ifdef USE_ADEPT2
#define NAMELIB "Using Adept 2.0 Library"
#include "adept.h"
#include "adept/Stack.h"
#include "adept/scalar_shortcuts.h"
//#include "adept_source.h"
#define STARTAD adept::Stack s1
#define STARTREC(in) s1.new_recording()
#define SETGRAD(in,out) out.set_gradient(in);s1.reverse()
#define GETGRAD(in) (in.get_gradient())
#define GETGRADV(in,i) (in[i].get_gradient())
#define GETGRADS(in,i) for_each( in.begin(), in.end(), [](double ss) { cout << ss; } );
typedef adept::adouble AReal;
#define LVAL adept::value(
#define RVAL )
#endif
typedef double Real;


inline Real adtan2(Real y, Real x)
{
    Real out=(Real) 0.0;
    if(x<0.0&&y==0.0)
        out=(Real)M_PI;
    else if(x==0.0&&y==0.0)
        throw new std::runtime_error("atan2 is not defined in the origin") ;
    else if(x!=0.0&&y!=0.0)
    {
        out=2*atan(y/(sqrt(x*x+y*y)+x));
    }
    return out;
}
inline AReal atan2(const AReal& y,const AReal& x)
{
    AReal  out=0.0;
    Real xval=LVAL x RVAL;
    Real yval=LVAL y RVAL;
    if(xval<0.0&&yval==0.0)
        out=(Real)M_PI;
    else if(xval==0.0&&yval==0.0)
        throw new std::runtime_error("atan2 is not defined in the origin") ;
    else if(xval!=0.0&&yval!=0.0)
    {
        out=2*atan(y/(sqrt(x*x+y*y)+x));
    }
    return out;
}
#endif //TESI_AATAN2_H
