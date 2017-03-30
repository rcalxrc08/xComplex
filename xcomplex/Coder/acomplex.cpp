//
// Created by nico on 1/26/17.
//


#include "../Include/acomplex.h"
typedef adept::adouble AReal;
typedef double Real;
acomplex operator+(Real c,const acomplex& in)
{
    return in+c;
}
acomplex operator-(Real c,const acomplex& in)
{
    return c+(-1.*in);
}

acomplex operator*(Real c,const acomplex& in)
{
    return in*c;
}

acomplex operator/(Real c,const acomplex& in)
{
//    AReal inv1=1./c;
    return in*(1./c);
}

acomplex operator+(const AReal& c,const acomplex& in)
{
    return in+c;
}
acomplex operator-(const AReal& c,const acomplex& in)
{
    return -1.*in+c;
}

acomplex operator*(const AReal& c,const acomplex& in)
{
    return in*c;
}

acomplex operator/(const AReal& c,const acomplex& in)
{
//    AReal inv1=1./c;
    return ((AReal)(1./c))*in;
}

acomplex acomplex::operator+(const dcomplex& cpx)
{
    /*AReal r=(*this).getReal()+cpx.getReal();
    AReal i=(*this).getImm()+cpx.getImm();
    acomplex outCpc=acomplex(r,i);*/

    return acomplex((*this).getReal()+ cpx.getReal(), (*this).getImm()+ cpx.getImm());
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
    /* AReal r=(*this).getReal()*cpx.getRealP()-(*this).getImmP()*cpx.getImmP();
     AReal i=(*this).getImm()*cpx.getRealP()+(*this).getReal()*cpx.getImm();
     acomplex outCpx=acomplex(r,i);*/

    return acomplex((*this).getReal()* cpx.getReal()- (*this).getImm()* cpx.getImm(), (*this).getImm()* cpx.getReal()+
                                                                                      (*this).getReal()* cpx.getImm());
}
acomplex acomplex::operator*=(const dcomplex& cpx)
{
    return (*this)*cpx;
}

acomplex acomplex::operator/(const dcomplex& cpx)
{
    dcomplex tmp=dcomplex(1.0,0.0);
    tmp=tmp/cpx;

    return (*this)*tmp;
}
acomplex acomplex::operator/=(const dcomplex& cpx)
{
    return (*this)/cpx;
}
