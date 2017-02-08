//
// Created by nico on 1/26/17.
//
#include "dcomplex.h"

////Mixed Operators FRIEND
dcomplex operator+(double c,const dcomplex& in)
{
    return in+c;
}
dcomplex operator-(double c,const dcomplex& in)
{
    return -1.*(in-c);
}
dcomplex operator*(double c,const dcomplex& in)
{
    return in*c;
}
dcomplex operator/(double c,const dcomplex& in)
{
    dcomplex tmp=dcomplex(c);
    return tmp/in;
}

acomplex operator+(const adept::adouble& c,const dcomplex& in)
{
    return in+c;
}
acomplex operator-(const adept::adouble& c,const dcomplex& in)
{
    return -1.*(in-c);
}
acomplex operator*(const adept::adouble& c,const dcomplex& in)
{
    return in*c;
}
acomplex operator/(const adept::adouble& c,const dcomplex& in)
{
    acomplex tmp=acomplex(c);

    return tmp/in;
}
////Acomplex

acomplex dcomplex::operator+(const acomplex& cpx)
const{
    adept::adouble r=(*this).getRealP()+cpx.getRealP();
    adept::adouble i=(*this).getImmP()+cpx.getImmP();
    acomplex outCpc=acomplex(r,i);

    return outCpc;
}
acomplex dcomplex::operator-(const acomplex& cpx)
const{
    adept::adouble r=(*this).getRealP()-cpx.getRealP();
    adept::adouble i=(*this).getImmP()-cpx.getImmP();
    acomplex outCpc=acomplex(r,i);

    return outCpc;
}
acomplex dcomplex::operator*(const acomplex& cpx)
const{
    adept::adouble r=(*this).getRealP()*cpx.getRealP()-(*this).getImmP()*cpx.getImmP();
    adept::adouble i=(*this).getImmP()*cpx.getRealP()+(*this).getRealP()*cpx.getImmP();
    acomplex outCpx=acomplex(r,i);

    return outCpx;
}
acomplex dcomplex::operator/(const acomplex& cpx)
const{
    adept::adouble r=(*this).getRealP()*cpx.getRealP()+(*this).getImmP()*cpx.getImmP();
    adept::adouble i=(*this).getImmP()*cpx.getRealP()-(*this).getRealP()*cpx.getImmP();
    adept::adouble Rho=cpx.getNormSqr();
    acomplex outCpx=acomplex(r/Rho,i/Rho);

    return outCpx;
}
////Adouble
acomplex dcomplex::operator+(const adept::adouble& c)
const{
    adept::adouble r=(*this).getRealP()+c;
    adept::adouble i=(*this).getImmP();
    acomplex outCpx=acomplex(r,i);

    return outCpx;
}
acomplex dcomplex::operator-(const adept::adouble& c)
const{
    adept::adouble r=(*this).getRealP()-c;
    adept::adouble i=(*this).getImmP();
    acomplex outCpx=acomplex(r,i);

    return outCpx;
}
acomplex dcomplex::operator*(const adept::adouble& c)
const{
    adept::adouble r=(*this).getRealP()*c;
    adept::adouble i=(*this).getImmP()*c;
    acomplex outCpx=acomplex(r,i);

    return outCpx;
}
acomplex dcomplex::operator/(const adept::adouble& c)
const{
    adept::adouble tm=1./c;
    acomplex outCpx=(*this)*tm;
    return outCpx;
}