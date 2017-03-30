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
acomplex operator/(const AReal& c,const dcomplex& in)
{
    acomplex tmp=acomplex(c,0.0);

    return tmp/in;
}
////Acomplex

acomplex dcomplex::operator+(const acomplex& cpx)
const{
    AReal r= (*this).getReal()+ cpx.getReal();
    AReal i= (*this).getImm()+ cpx.getImm();
    acomplex outCpc=acomplex(r,i);

    return outCpc;
}
acomplex dcomplex::operator-(const acomplex& cpx)
const{
    AReal r= (*this).getReal()- cpx.getReal();
    AReal i= (*this).getImm()- cpx.getImm();
    acomplex outCpc=acomplex(r,i);

    return outCpc;
}
acomplex dcomplex::operator*(const acomplex& cpx)
const{
    AReal r= (*this).getReal()* cpx.getReal()- (*this).getImm()* cpx.getImm();
    AReal i= (*this).getImm()* cpx.getReal()+ (*this).getReal()* cpx.getImm();
    acomplex outCpx=acomplex(r,i);

    return outCpx;
}
acomplex dcomplex::operator/(const acomplex& cpx)
const{
    AReal r= (*this).getReal()* cpx.getReal()+ (*this).getImm()* cpx.getImm();
    AReal i= (*this).getImm()* cpx.getReal()- (*this).getReal()* cpx.getImm();
    AReal Rho=cpx.getNormSqr();
    acomplex outCpx=acomplex(r/Rho,i/Rho);

    return outCpx;
}
////Adouble
acomplex dcomplex::operator+(const AReal& c)
const{
    AReal r= (*this).getReal()+c;
    AReal i= (*this).getImm();
    acomplex outCpx=acomplex(r,i);

    return outCpx;
}
acomplex dcomplex::operator-(const AReal& c)
const{
    AReal r= (*this).getReal()-c;
    AReal i= (*this).getImm();
    acomplex outCpx=acomplex(r,i);

    return outCpx;
}
acomplex dcomplex::operator*(const AReal& c)
const{
    AReal r= (*this).getReal()*c;
    AReal i= (*this).getImm()*c;
    acomplex outCpx=acomplex(r,i);

    return outCpx;
}
acomplex dcomplex::operator/(const AReal& c)
const{
    AReal tm=1./c;
    acomplex outCpx=(*this)*tm;
    return outCpx;
}
