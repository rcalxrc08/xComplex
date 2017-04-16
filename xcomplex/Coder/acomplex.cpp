//
// Created by nico on 1/26/17.
//


#include "../Include/acomplex.h"
#ifdef USE_ADEPT
#include "adept_source.h"
#endif
#ifdef USE_ADDICT
DECLARE_ADGRAPH();
#endif
acomplex acomplex::operator+(const dcomplex& cpx)
{
    /*AReal r=re+cpx.re;
    AReal i=im+cpx.im;
    acomplex outCpc=acomplex(r,i);*/

    return acomplex(re+ cpx.re, im+ cpx.im);
}
acomplex acomplex::operator+=(const dcomplex& cpx)
{
    return (*this)+cpx;
}

acomplex acomplex::operator-(const dcomplex& cpx)
{
//    dcomplex tmp=-1.*cpx;
    return (*this)+(-1.*cpx);
}
acomplex acomplex::operator-=(const dcomplex& cpx)
{
    return (*this)-cpx;
}

acomplex acomplex::operator*(const dcomplex& cpx)
{
    /* AReal r=re*cpx.getRealP()-(*this).getImmP()*cpx.getImmP();
     AReal i=im*cpx.getRealP()+re*cpx.im;
     acomplex outCpx=acomplex(r,i);*/

    return acomplex(re* cpx.re- im* cpx.im, im* cpx.re+
                                            re* cpx.im);
}
acomplex acomplex::operator*=(const dcomplex& cpx)
{
    return (*this)*cpx;
}

acomplex acomplex::operator/(const dcomplex& cpx)
{
    /* dcomplex tmp=dcomplex(1.0,0.0);
     tmp=tmp/cpx;*/

//    return (*this)*tmp;
    return acomplex((re*cpx.re+im*cpx.im)/cpx.getNormSqr(),(im*cpx.re-re*cpx.im)/cpx.getNormSqr());
}

acomplex acomplex::operator/=(const dcomplex& cpx)
{
    return (*this)/cpx;
}