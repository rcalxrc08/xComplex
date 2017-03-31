//
// Created by nico on 1/18/17.
//

#ifndef TESI_AATAN2_H
#define TESI_AATAN2_H

#include <math.h>
#include <stdexcept>

#ifdef CL_TAPE_CPPAD
#include <map>
#include <fstream>
#include <cl/tape/impl/detail/enable_ad.hpp>
#include <cl/tape/util/testoutput.hpp>
#include <cl/tape/tape.hpp>
typedef cl::tdouble AReal;
#define LVAL (Real)
#define RVAL
#endif

#ifdef USE_ADEPT
#include "../../Adept/adept.h"
typedef adept::adouble AReal;
#define LVAL
#define RVAL .value()
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
inline AReal atan2(AReal y, AReal x)
{
    AReal  out=0.0;
    Real xval=LVAL x RVAL;
    Real yval=LVAL x RVAL;
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
