//
// Created by nico on 1/28/17.
//
#include "adatan2.h"
#include "adept.h"

adept::adouble adtan2(adept::adouble y, adept::adouble x)
{
    adept::adouble  out=0.0;
    if(x.value()<0.0&&y.value()==0.0)
        out=(double)M_PI;
    else if(x.value()==0.0&&y.value()==0.0)
        throw new std::runtime_error("atan2 is not defined in the origin") ;
    else if(x.value()!=0.0&&y.value()!=0.0)
    {
       /* adept::adouble  tm1=x*x+y*y;
        adept::adouble  den=pow(tm1,0.5)+x;
        y/=den;*/
        out=2*atan(y/(sqrt(x*x+y*y)+x));
    }
    return out;
}

double adtan2(double y, double x)
{
    double out=(double) 0.0;
    if(x<0.0&&y==0.0)
        out=(double)M_PI;
    else if(x==0.0&&y==0.0)
        throw new std::runtime_error("atan2 is not defined in the origin") ;
    else if(x!=0.0&&y!=0.0)
    {
        out=2*atan(y/(sqrt(x*x+y*y)+x));
    }
    return out;
}
