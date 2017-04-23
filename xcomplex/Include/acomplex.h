//
// Created by nico on 1/25/17.
//

#ifndef TESI_ACOMPLEX_H
#define TESI_ACOMPLEX_H

//friend acomplex exp(const acomplex& in)
//{
//
//    return acomplex(exp(in.re)*cos(in.im),exp(in.re)*sin(in.im));
//}


#include <cmath>
#include <vector>
#include "adatan2.h"
#include "dcomplex.h"
#define ImagUnit "j"
//// All is passed by reference
class dcomplex;

#ifdef CL_TAPE_CPPAD
using namespace std;
#endif

#ifdef USE_ADDICT
using namespace ad;
#endif

//inline acomplex operator+(const acomplex& cpx) //Acomplex SUM
//const{
//    return acomplex(re + cpx.re,im + cpx.im);
//}
class acomplex
{
#define FUNCDEFINE(fun,RealPart,ImmaginaryPart)friend acomplex fun (const acomplex& in) {return acomplex(RealPart,ImmaginaryPart); }
#define ACPXOPDEFINE(OP,RealPart,ImmaginaryPart) inline acomplex operator OP (const acomplex& cpx) const{return acomplex(RealPart,ImmaginaryPart);}
#define ACPXOPEQDEFINE(OP,Complex) inline acomplex operator OP (const acomplex& cpx) const{return Complex;}

public:////Attributse
    AReal re;
    AReal im;
public:
    explicit acomplex () {}
    explicit acomplex (const AReal& RealP,const AReal& im) :re(RealP),im(im){}
////IntraClass Operators
    AReal getReal() const {return re;}

    AReal getImm() const {return im;}

    AReal getRho() const { return sqrt(re*re+im*im);}

    AReal getTheta() const { return atan2(im, re);}

    AReal getNormSqr() const {return re*re+im*im;}

    friend std::ostream& operator<<(std::ostream& os, acomplex& obj)
    {
        AReal tmpIM=(-1.0*obj.im);
        Real tmp1=LVAL tmpIM RVAL;
        Real re=LVAL obj.re RVAL;
        Real im=LVAL obj.im RVAL;
        if(obj.im>=0.0)
            os<<re<<" + "<<ImagUnit<<" "<<im;
        else
            os<<re<<" - "<<ImagUnit<<" "<<(tmp1);

        return os;
    }
////InterClass Operators
    bool operator==(acomplex& o)
    {
        return (im==o.im&&re==o.re);
    }

    bool operator!=(acomplex& o)
    {
        return !((*this)==o);
    }

////acomplex op AReal
#define ACPXOPAREAL(OP,RealP,ImmP) inline acomplex operator OP (const AReal& arealNum) const { return acomplex(RealP,ImmP);}
    ACPXOPAREAL(+,re+arealNum,im);
    ACPXOPAREAL(-,re-arealNum,im);
    ACPXOPAREAL(*,re*arealNum,im*arealNum);
    ACPXOPAREAL(/,re/arealNum,im/arealNum);
#define ACPXOPEQAREAL(OP,ACOMPLEX) inline acomplex operator OP (const AReal& arealNum) const { return ACOMPLEX; }

    ACPXOPEQAREAL(+=, (*this)+arealNum);
    ACPXOPEQAREAL(-=, (*this)-arealNum);
    ACPXOPEQAREAL(*=, (*this)*arealNum);
    ACPXOPEQAREAL(/=, (*this)/arealNum);

#define ACPXOPREAL(OP,RealP,ImmP) inline acomplex operator OP (const Real& realNum) const { return acomplex(RealP,ImmP);}
    ////Acomplex op Real
    ACPXOPREAL(+,re+realNum,im);
    ACPXOPREAL(-,re-realNum,im);
    ACPXOPREAL(*,re*realNum,im*realNum);
    ACPXOPREAL(/,re/realNum,im/realNum);
#define ACPXOPEQREAL(OP,ACOMPLEX) inline acomplex operator OP (const Real& realNum) const { return ACOMPLEX;}
    ////op=
    ACPXOPEQREAL(+=,(*this)+realNum);
    ACPXOPEQREAL(-=,(*this)-realNum);
    ACPXOPEQREAL(*=,(*this)*realNum);
    ACPXOPEQREAL(/=,(*this)/realNum);



    ////Real op Acomplex
#define DECLFRNDMIX(OP) friend acomplex operator OP (Real c,const acomplex& in);
    DECLFRNDMIX(+)
    DECLFRNDMIX(-)
    DECLFRNDMIX(*)
    DECLFRNDMIX(/)

    ////AReal op Acomplex
#define DECLFRNDMIX2(OP) friend acomplex operator OP (const AReal& arealNum,const acomplex& in);
    DECLFRNDMIX2(+)
    DECLFRNDMIX2(-)
    DECLFRNDMIX2(*)
    DECLFRNDMIX2(/)

    ////Acomplex op Acomplex
    ACPXOPDEFINE(+,re+cpx.re,im+cpx.im)
    ACPXOPDEFINE(-,re-cpx.re,im-cpx.im)
    ACPXOPDEFINE(*,re*cpx.re-im*cpx.im,im*cpx.re+re*cpx.im)
    ACPXOPDEFINE(/,(re*cpx.re+im*cpx.im)/cpx.getNormSqr(),(im*cpx.re-re*cpx.im)/cpx.getNormSqr())
    ////Acomplex op= Acomplex
    ACPXOPEQDEFINE(+=,(*this)+cpx)
    ACPXOPEQDEFINE(-=,(*this)-cpx)
    ACPXOPEQDEFINE(*=,(*this)*cpx)
    ACPXOPEQDEFINE(/=,(*this)/cpx)


    ////acomplex op dcomplex
#define DECLACPXDCPX(OP) acomplex operator OP (const dcomplex& cpx);
    DECLACPXDCPX(+)
    DECLACPXDCPX(-)
    DECLACPXDCPX(*)
    DECLACPXDCPX(/)
    ////op=
    DECLACPXDCPX(+=)
    DECLACPXDCPX(-=)
    DECLACPXDCPX(*=)
    DECLACPXDCPX(/=)

////Mathematical Operations

    FUNCDEFINE(exp,exp(in.re)*cos(in.im),exp(in.re)*sin(in.im))
    FUNCDEFINE(cos,cosh((in).im)*cos((in).re),-1.*sin((in).re)*sinh((in).im))
    FUNCDEFINE(sin,sin(in.re)*cosh(in.im),cos((in).re)*sinh((in).im))
    FUNCDEFINE(log,log(in.getRho()),in.getTheta())
    friend acomplex pow(const acomplex& in,const AReal& n)
    {

        return acomplex(cos(n*in.getTheta())*pow(in.getRho(),LVAL n RVAL),sin(n*in.getTheta())*pow(in.getRho(),LVAL n RVAL));
    }

    friend acomplex pow(const acomplex& in,const Real& n)
    {

        return acomplex(cos(n*in.getTheta())*pow(in.getRho(),n),sin(n*in.getTheta())*pow(in.getRho(),n));
    }

    friend acomplex tan(const acomplex& in)
    {
        //TODO Optimize function tangent for acomplex

        return sin(in)/cos(in);
    }
    friend void swap(acomplex& a, acomplex& b)
    {

        std::swap(a.re, b.re);
        std::swap(a.im, b.im);
    }
};

////acomplex.cpp
////Real op acomplex
inline acomplex operator+(Real realNum,const acomplex& in)
{
    return in+realNum;
}

inline acomplex operator-(Real realNum,const acomplex& in)
{
    return realNum+(-1.*in);
}

inline acomplex operator*(Real realNum,const acomplex& in)
{
    return in*realNum;
}

inline acomplex operator/(Real realNum,const acomplex& in)
{
    return in*(1./realNum);
}
////op=


////AReal op acomplex
inline acomplex operator+(const AReal& arealNum,const acomplex& in)
{
    return in+arealNum;
}
inline acomplex operator-(const AReal& arealNum,const acomplex& in)
{
    return -1.*in+arealNum;
}

inline acomplex operator*(const AReal& arealNum,const acomplex& in)
{
    return in*arealNum;
}

inline acomplex operator/(const AReal& arealNum,const acomplex& in)
{
    return ((AReal)(1./arealNum))*in;
}

#endif //TESI_ACOMPLEX_H
