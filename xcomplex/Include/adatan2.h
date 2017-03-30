//
// Created by nico on 1/18/17.
//

#ifndef TESI_AATAN2_H
#define TESI_AATAN2_H

#include <math.h>
#include <stdexcept>
#include "../../Adept/adept.h"

typedef double Real;
typedef adept::adouble AReal;

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
inline AReal adtan2(AReal y, AReal x)
{
    AReal  out=0.0;
    Real xval=x.value();
    Real yval=y.value();
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
