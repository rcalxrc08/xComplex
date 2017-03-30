//
// Created by nico on 1/26/17.
//
#include "../Include/dcomplex.h"

////Mixed Operators FRIEND

typedef adept::adouble AReal;

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
acomplex operator/(const AReal& c,const dcomplex& in)
{
    acomplex tmp=acomplex(c);

    return tmp/in;
}
////Acomplex

acomplex dcomplex::operator+(const acomplex& cpx)
const{
    AReal r=(*this).getRealP()+cpx.getRealP();
    AReal i=(*this).getImmP()+cpx.getImmP();
    acomplex outCpc=acomplex(r,i);

    return outCpc;
}
acomplex dcomplex::operator-(const acomplex& cpx)
const{
    AReal r=(*this).getRealP()-cpx.getRealP();
    AReal i=(*this).getImmP()-cpx.getImmP();
    acomplex outCpc=acomplex(r,i);

    return outCpc;
}
acomplex dcomplex::operator*(const acomplex& cpx)
const{
    AReal r=(*this).getRealP()*cpx.getRealP()-(*this).getImmP()*cpx.getImmP();
    AReal i=(*this).getImmP()*cpx.getRealP()+(*this).getRealP()*cpx.getImmP();
    acomplex outCpx=acomplex(r,i);

    return outCpx;
}
acomplex dcomplex::operator/(const acomplex& cpx)
const{
    AReal r=(*this).getRealP()*cpx.getRealP()+(*this).getImmP()*cpx.getImmP();
    AReal i=(*this).getImmP()*cpx.getRealP()-(*this).getRealP()*cpx.getImmP();
    AReal Rho=cpx.getNormSqr();
    acomplex outCpx=acomplex(r/Rho,i/Rho);

    return outCpx;
}
////Adouble
acomplex dcomplex::operator+(const AReal& c)
const{
    AReal r=(*this).getRealP()+c;
    AReal i=(*this).getImmP();
    acomplex outCpx=acomplex(r,i);

    return outCpx;
}
acomplex dcomplex::operator-(const AReal& c)
const{
    AReal r=(*this).getRealP()-c;
    AReal i=(*this).getImmP();
    acomplex outCpx=acomplex(r,i);

    return outCpx;
}
acomplex dcomplex::operator*(const AReal& c)
const{
    AReal r=(*this).getRealP()*c;
    AReal i=(*this).getImmP()*c;
    acomplex outCpx=acomplex(r,i);

    return outCpx;
}
acomplex dcomplex::operator/(const AReal& c)
const{
    AReal tm=1./c;
    acomplex outCpx=(*this)*tm;
    return outCpx;
}