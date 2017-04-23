//
// Created by nico on 1/26/17.
//
#include "../Include/dcomplex.h"
//TODO Rifai le interazioni con gli adouble e acomplex
////Mixed Operators FRIEND
//#define MIXEDOPERATOR2(OP,ACOMPLEX) acomplex operator OP (const AReal& c,const dcomplex& in) {return ACOMPLEX;}
#define MIXEDOPERATOR2(OP,RealP,ImmP) acomplex operator OP (const AReal& c,const dcomplex& in) {return acomplex(RealP,ImmP);}
MIXEDOPERATOR2(+,in.re+c,in.im)
MIXEDOPERATOR2(-, c-in.re,-in.im)
MIXEDOPERATOR2(*,c*in.re,c*in.im)
MIXEDOPERATOR2(/,(c*in.re)/in.getNormSqr(),(-c*in.im)/in.getNormSqr())
////Acomplex
#define MIXEDOPERATOR11(OP,RealP,ImmP) acomplex dcomplex::operator OP (const acomplex& cpx) const {return acomplex(RealP,ImmP);}
MIXEDOPERATOR11(+,(*this).re+ cpx.re,(*this).im+ cpx.im);
MIXEDOPERATOR11(-,(*this).re- cpx.re, (*this).im- cpx.im);
MIXEDOPERATOR11(*,(*this).re* cpx.re- (*this).im* cpx.im,(*this).im* cpx.re+ (*this).re* cpx.im);
MIXEDOPERATOR11(/, ((*this).re* cpx.re+ (*this).im* cpx.im)/cpx.getNormSqr(),((*this).im* cpx.re- (*this).re* cpx.im)/cpx.getNormSqr());

#define AREALMIXOP(OP,RealP,ImmP) acomplex dcomplex::operator OP (const AReal& c) const{return acomplex( RealP,ImmP);}
////Adouble
AREALMIXOP(+,(*this).re+c,(*this).im);
AREALMIXOP(-,(*this).re-c,(*this).im);
AREALMIXOP(*,(*this).re*c,(*this).im*c);
AREALMIXOP(/,(*this).re/c,(*this).im/c);
