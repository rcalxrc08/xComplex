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
    /*AReal r= (*this).getReal()+ cpx.getReal();
    AReal i= (*this).getImm()+ cpx.getImm();*/
//    acomplex outCpc=acomplex((*this).getReal()+ cpx.getReal(),(*this).getImm()+ cpx.getImm());

    return acomplex((*this).getReal()+ cpx.getReal(),(*this).getImm()+ cpx.getImm());
}
acomplex dcomplex::operator-(const acomplex& cpx)
const{
    /* AReal r= (*this).getReal()- cpx.getReal();
     AReal i= (*this).getImm()- cpx.getImm();*/
//    acomplex outCpc=acomplex((*this).getReal()- cpx.getReal(), (*this).getImm()- cpx.getImm());

    return acomplex((*this).getReal()- cpx.getReal(), (*this).getImm()- cpx.getImm());
}
acomplex dcomplex::operator*(const acomplex& cpx)
const{
    /*  AReal r= (*this).getReal()* cpx.getReal()- (*this).getImm()* cpx.getImm();
      AReal i= (*this).getImm()* cpx.getReal()+ (*this).getReal()* cpx.getImm();
      acomplex outCpx=acomplex((*this).getReal()* cpx.getReal()- (*this).getImm()* cpx.getImm(),(*this).getImm()* cpx.getReal()+ (*this).getReal()* cpx.getImm());*/

    return acomplex((*this).getReal()* cpx.getReal()- (*this).getImm()* cpx.getImm(),(*this).getImm()* cpx.getReal()+ (*this).getReal()* cpx.getImm());
}
acomplex dcomplex::operator/(const acomplex& cpx)
const{
    /*AReal r= ((*this).getReal()* cpx.getReal()+ (*this).getImm()* cpx.getImm());
    AReal i= ((*this).getImm()* cpx.getReal()- (*this).getReal()* cpx.getImm());
    AReal Rho=cpx.getNormSqr();*/
//    acomplex outCpx=acomplex( ((*this).getReal()* cpx.getReal()+ (*this).getImm()* cpx.getImm())/cpx.getNormSqr(),((*this).getImm()* cpx.getReal()- (*this).getReal()* cpx.getImm())/cpx.getNormSqr());

    return acomplex( ((*this).getReal()* cpx.getReal()+ (*this).getImm()* cpx.getImm())/cpx.getNormSqr(),((*this).getImm()* cpx.getReal()- (*this).getReal()* cpx.getImm())/cpx.getNormSqr());
}
////Adouble
acomplex dcomplex::operator+(const AReal& c)
const{
    /*AReal r= (*this).getReal()+c;
    AReal i= (*this).getImm();
    acomplex outCpx=acomplex( (*this).getReal()+c,(*this).getImm());*/

    return acomplex( (*this).getReal()+c,(*this).getImm());
}
acomplex dcomplex::operator-(const AReal& c)
const{
/*    AReal r= (*this).getReal()-c;
    AReal i= (*this).getImm();*/
//    acomplex outCpx=acomplex((*this).getReal()-c,(*this).getImm());

    return acomplex((*this).getReal()-c,(*this).getImm());
}
acomplex dcomplex::operator*(const AReal& c)
const{
    /*AReal r= (*this).getReal()*c;
    AReal i= (*this).getImm()*c;
    acomplex outCpx=acomplex((*this).getReal()*c,(*this).getImm()*c);*/

    return acomplex((*this).getReal()*c,(*this).getImm()*c);
}
acomplex dcomplex::operator/(const AReal& c)
const{
/*    AReal tm=1./c;
    acomplex outCpx=(*this)*tm;*/
    return acomplex((*this).getReal()/c,(*this).getImm()/c);
}
