//
// Created by nico on 1/25/17.
//

#ifndef TESI_DCOMPLEX_H
#define TESI_DCOMPLEX_H
#define ImagUnit "j"

////Include
#include <cmath>
#include <vector>
#include <iostream>
#include "adatan2.h"
#include "acomplex.h"

class acomplex;

class dcomplex
{
public:////Attributes
    Real re;
    Real im;
public:
    explicit dcomplex(const Real& RealP=0.0,const Real& im=0.0):re(RealP),im(im){}

    Real getReal() const{return re;}

//    void setRealP(Real& real) {re = real;}

    Real getImm() const{return im;}

//    void setim(Real& imm) {im = imm;}

    Real getRho()const {return sqrt(re*re+im*im);}

    Real getTheta()const {return atan2(im,re);}

    Real getNormSqr() const{return re*re+im*im;}

////Direct Operators
    bool operator==(dcomplex& o)
    {
        return ((*this).im==o.im&&(*this).re==o.re);
    }

    bool operator!=(dcomplex& o)
    {
        return !((*this)==o);
    }

    dcomplex operator+(const dcomplex& cpx)
    const {
        /*Real r=(*this).re+cpx.re;
        Real i=(*this).im+cpx.im;
        dcomplex outCpc=dcomplex(r,i);*/

        return dcomplex((*this).re+cpx.re,(*this).im+cpx.im);
    }

    dcomplex operator+=(const dcomplex& cpx)
    const {
        return (*this)+cpx;
    }

    dcomplex operator-(const dcomplex& cpx)
    const {
        return dcomplex((*this).re-cpx.re,(*this).im-cpx.im);;
    }

    dcomplex operator-=(const dcomplex& cpx)
    const {
        return *this-cpx;
    }

    dcomplex operator*(const dcomplex& cpx)
    const{
        return dcomplex((*this).re*cpx.re-(*this).im*cpx.im,(*this).im*cpx.re+(*this).re*cpx.im);
    }

    dcomplex operator*=(const dcomplex& cpx)
    const{
        return (*this)*cpx;
    }



    dcomplex operator/(const dcomplex& cpx)
    const{
        return dcomplex(((*this).re*cpx.re+(*this).im*cpx.im)/cpx.getNormSqr(),((*this).im*cpx.re-(*this).re*cpx.im)/cpx.getNormSqr());
    }


    dcomplex operator/=(const dcomplex& cpx)
    const{
        return (*this)/cpx;
    }

    friend std::ostream& operator<<(std::ostream& os, dcomplex& obj)
    {
        Real tmp1=-1.0*obj.im;
        if(obj.im>=0.0)
            os<<obj.re<<" + "<<ImagUnit<<" "<<obj.im<<std::endl;
        else
            os<<obj.re<<" - "<<ImagUnit<<" "<<(tmp1)<<std::endl;
        return os;
    }
////Double Operators
    friend dcomplex operator+(Real c,const dcomplex& in);
    friend dcomplex operator-(Real c,const dcomplex& in);
    friend dcomplex operator*(Real c,const dcomplex& in);
    friend dcomplex operator/(Real c,const dcomplex& in);

    friend acomplex operator+(const AReal& c,const dcomplex& in);
    friend acomplex operator-(const AReal& c,const dcomplex& in);
    friend acomplex operator*(const AReal& c,const dcomplex& in);
    friend acomplex operator/(const AReal& c,const dcomplex& in);

    dcomplex operator+(const Real& c)
    const{
        return dcomplex(c+(*this).re,(*this).im);
    }
    dcomplex operator-(const Real& c)
    const{
        return dcomplex((*this).re-c,(*this).im);
    }
    dcomplex operator*(const Real& c)
    const{
        return dcomplex(c*(*this).re,c*(*this).im);
    }
    dcomplex operator/(const Real& c)
    const{
        return (*this)*(1./c);
    }

    dcomplex operator+=(const Real& num)
    const{
        return (*this)+num;
    }
    dcomplex operator-=(const Real& num)
    const{
        return (*this)-num;
    }
    dcomplex operator*=(const Real& num)
    const{
        return (*this)*num;
    }
    dcomplex operator/=(const Real& num)
    const{
        return (*this)/num;
    }

////Mixed Operators
////Adouble

    acomplex operator*(const AReal& c)const;////ADJ
    acomplex operator/(const AReal& c)const;////ADJ
    acomplex operator+(const AReal& c)const;////ADJ
    acomplex operator-(const AReal& c)const;////ADJ
////Acomplex
    acomplex operator-(const acomplex& cpx)const;////ADJ
    acomplex operator+(const acomplex& cpx)const;////ADJ
    acomplex operator/(const acomplex& cpx)const;////ADJ
    acomplex operator*(const acomplex& cpx)const;////ADJ

////Mathematical Operations

    friend dcomplex pow(const dcomplex& in,const Real& n)
    {
        Real Rho=in.getRho();
        Rho=std::pow(Rho,n);
        Real Theta=n*in.getTheta();
        dcomplex outCpx=dcomplex(std::cos(Theta)*Rho,std::sin(Theta)*Rho);

        return outCpx;
    }

    friend dcomplex exp(const dcomplex& in)
    {
        Real r1=std::exp(in.re);
        Real i1=in.im;

        return dcomplex(r1*std::cos(i1),r1*std::sin(i1));
    }

    friend dcomplex cos(const dcomplex& in)
    {
        Real r1=(in).re;
        Real i1=(in).im;
        Real r=std::cos(r1)*cosh(i1);
        Real i=std::sin(-r1)*sinh(i1);
        dcomplex outCpx=dcomplex(r,i);

        return outCpx;
    }

    friend dcomplex sin(const dcomplex& in)
    {
        Real r1=(in).re;
        Real i1=(in).im;
        Real r=std::sin(r1)*cosh(i1);
        Real i=std::cos(r1)*sinh(i1);
        dcomplex outCpx=dcomplex(r,i);

        return outCpx;
    }

    friend dcomplex tan(const dcomplex& in)
    {
        dcomplex tmp1=sin(in);
        dcomplex tmp2=cos(in);
        dcomplex outCpx=tmp1 / tmp2;

        return outCpx;
    }

    friend dcomplex log(const dcomplex& in)
    {
        Real r=std::log(in.getRho());
        Real i=in.getTheta();
        dcomplex outCpx=dcomplex(r,i);

        return outCpx;
    }
    friend void swap(dcomplex& a, dcomplex& b)
    {
        std::swap(a.re, b.re);
        std::swap(a.im, b.im);
    }
};

inline dcomplex operator+(Real c,const dcomplex& in)
{
    return in+c;
}
inline dcomplex operator-(Real c,const dcomplex& in)
{
    return -1.*(in-c);
}
inline dcomplex operator*(Real c,const dcomplex& in)
{
    return in*c;
}
inline dcomplex operator/(Real c,const dcomplex& in)
{
    dcomplex tmp=dcomplex(c);
    return tmp/in;
}
#endif //TESI_DCOMPLEX_H
