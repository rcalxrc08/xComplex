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

#define MIXEDOPERATOR1(OP,Real,Imm) acomplex acomplex::operator OP (const dcomplex& cpx) { return acomplex(Real,Imm); }
#define MIXEDOPERATOREQ1(OP,Complex) acomplex acomplex::operator OP (const dcomplex& cpx) { return Complex; }

MIXEDOPERATOR1(+,re+cpx.re,im+cpx.im)
MIXEDOPERATOR1(-,re-cpx.re,im-cpx.im)
MIXEDOPERATOR1(*,re* cpx.re- im* cpx.im,im* cpx.re+re* cpx.im)
MIXEDOPERATOR1(/,(re*cpx.re+im*cpx.im)/cpx.getNormSqr(),(im*cpx.re-re*cpx.im)/cpx.getNormSqr())

MIXEDOPERATOREQ1(+=,(*this)+cpx)
MIXEDOPERATOREQ1(-=,(*this)-cpx)
MIXEDOPERATOREQ1(*=,(*this)*cpx)
MIXEDOPERATOREQ1(/=,(*this)/cpx)