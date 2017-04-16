//
// Created by nico on 1/26/17.
//
#include "../Include/dcomplex.h"
//TODO Rifai le interazioni con gli adouble e acomplex
////Mixed Operators FRIEND

acomplex operator+(const AReal& c,const dcomplex& in)
{
    return in+c;
}
acomplex operator-(const AReal& c,const dcomplex& in)
{
    return -1.*(in-c);
}
acomplex operator*(const AReal& c,const dcomplex& in)
{
    return in*c;
}
acomplex operator/(const AReal& c,const dcomplex& cpx)
{
    return acomplex((c*cpx.re)/cpx.getNormSqr(),(-c*cpx.im)/cpx.getNormSqr());
}
////Acomplex

acomplex dcomplex::operator+(const acomplex& cpx)
const{
    /*AReal r= (*this).re+ cpx.re;
    AReal i= (*this).im+ cpx.im;*/
//    acomplex outCpc=acomplex((*this).re+ cpx.re,(*this).im+ cpx.im);

    return acomplex((*this).re+ cpx.re,(*this).im+ cpx.im);
}
acomplex dcomplex::operator-(const acomplex& cpx)
const{
    /* AReal r= (*this).re- cpx.re;
     AReal i= (*this).im- cpx.im;*/
//    acomplex outCpc=acomplex((*this).re- cpx.re, (*this).im- cpx.im);

    return acomplex((*this).re- cpx.re, (*this).im- cpx.im);
}
acomplex dcomplex::operator*(const acomplex& cpx)
const{
    /*  AReal r= (*this).re* cpx.re- (*this).im* cpx.im;
      AReal i= (*this).im* cpx.re+ (*this).re* cpx.im;
      acomplex outCpx=acomplex((*this).re* cpx.re- (*this).im* cpx.im,(*this).im* cpx.re+ (*this).re* cpx.im);*/

    return acomplex((*this).re* cpx.re- (*this).im* cpx.im,(*this).im* cpx.re+ (*this).re* cpx.im);
}
acomplex dcomplex::operator/(const acomplex& cpx)
const{
    /*AReal r= ((*this).re* cpx.re+ (*this).im* cpx.im);
    AReal i= ((*this).im* cpx.re- (*this).re* cpx.im);
    AReal Rho=cpx.getNormSqr();*/
//    acomplex outCpx=acomplex( ((*this).re* cpx.re+ (*this).im* cpx.im)/cpx.getNormSqr(),((*this).im* cpx.re- (*this).re* cpx.im)/cpx.getNormSqr());

    return acomplex( ((*this).re* cpx.re+ (*this).im* cpx.im)/cpx.getNormSqr(),((*this).im* cpx.re- (*this).re* cpx.im)/cpx.getNormSqr());
}
////Adouble
acomplex dcomplex::operator+(const AReal& c)
const{
    /*AReal r= (*this).re+c;
    AReal i= (*this).im;
    acomplex outCpx=acomplex( (*this).re+c,(*this).im);*/

    return acomplex( (*this).re+c,(*this).im);
}
acomplex dcomplex::operator-(const AReal& c)
const{
/*    AReal r= (*this).re-c;
    AReal i= (*this).im;*/
//    acomplex outCpx=acomplex((*this).re-c,(*this).im);

    return acomplex((*this).re-c,(*this).im);
}
acomplex dcomplex::operator*(const AReal& c)
const{
    /*AReal r= (*this).re*c;
    AReal i= (*this).im*c;
    acomplex outCpx=acomplex((*this).re*c,(*this).im*c);*/

    return acomplex((*this).re*c,(*this).im*c);
}
acomplex dcomplex::operator/(const AReal& c)
const{
/*    AReal tm=1./c;
    acomplex outCpx=(*this)*tm;*/
    return acomplex((*this).re/c,(*this).im/c);
}
