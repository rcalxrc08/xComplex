//
// Created by nico on 1/25/17.
//

#ifndef TESI_DCOMPLEX_H
#define TESI_DCOMPLEX_H
#define ImagUnit "j"

////Include
#include <cmath>
#include <vector>
#include "../../Adept/adept.h"
#include "adatan2.h"
#include "acomplex.h"

class acomplex;

class dcomplex
{
private:
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
        return ((*this).getImm()==o.getImm()&&(*this).getReal()==o.getReal());
    }

    bool operator!=(dcomplex& o)
    {
        return !((*this)==o);
    }

    dcomplex operator+(const dcomplex& cpx)
    const {
        /*Real r=(*this).getReal()+cpx.getReal();
        Real i=(*this).getImm()+cpx.getImm();
        dcomplex outCpc=dcomplex(r,i);*/

        return dcomplex((*this).getReal()+cpx.getReal(),(*this).getImm()+cpx.getImm());
    }



    dcomplex operator+=(const dcomplex& cpx)
    const {
        return (*this)+cpx;
    }

    dcomplex operator-(const dcomplex& cpx)
    const {

//        dcomplex outCpc=dcomplex((*this).getReal()-cpx.getReal(),(*this).getImm()-cpx.getImm());

        return dcomplex((*this).getReal()-cpx.getReal(),(*this).getImm()-cpx.getImm());;
    }

    dcomplex operator-=(const dcomplex& cpx)
    const {
        return *this-cpx;
    }

    dcomplex operator*(const dcomplex& cpx)
    const{
        /*Real r=(*this).getReal()*cpx.getReal()-(*this).getImm()*cpx.getImm();
        Real i=(*this).getImm()*cpx.getReal()+(*this).getReal()*cpx.getImm();
        dcomplex outCpx=dcomplex(r,i);*/

        return dcomplex((*this).getReal()*cpx.getReal()-(*this).getImm()*cpx.getImm(),(*this).getImm()*cpx.getReal()+(*this).getReal()*cpx.getImm());
    }




    dcomplex operator*=(const dcomplex& cpx)
    const{
        return (*this)*cpx;
    }



    dcomplex operator/(const dcomplex& cpx)
    const{
        /*Real r=((*this).getReal()*cpx.getReal()+(*this).getImm()*cpx.getImm());
        Real i=((*this).getImm()*cpx.getReal()-(*this).getReal()*cpx.getImm());
        Real Rho=cpx.getNormSqr();
        dcomplex outCpx=dcomplex(r/Rho,i/Rho);*/

        return dcomplex(((*this).getReal()*cpx.getReal()+(*this).getImm()*cpx.getImm())/cpx.getNormSqr(),((*this).getImm()*cpx.getReal()-(*this).getReal()*cpx.getImm())/cpx.getNormSqr());
    }


    dcomplex operator/=(const dcomplex& cpx)
    const{
        return (*this)/cpx;
    }

    friend std::ostream& operator<<(std::ostream& os, dcomplex& obj)
    {
        Real tmp1=-1.0*obj.getImm();
        if(obj.getImm()>=0.0)
            os<<obj.getReal()<<" + "<<ImagUnit<<" "<<obj.getImm()<<std::endl;
        else
            os<<obj.getReal()<<" - "<<ImagUnit<<" "<<(tmp1)<<std::endl;

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
        /* Real r=c+(*this).getReal();
         dcomplex outCpx=dcomplex(r,(*this).getImm());*/

        return dcomplex(c+(*this).getReal(),(*this).getImm());
    }
    dcomplex operator-(const Real& c)
    const{
        /*Real r=(*this).getReal()-c;
        dcomplex outCpx=dcomplex(r,(*this).getImm());*/

        return dcomplex((*this).getReal()-c,(*this).getImm());
    }
    dcomplex operator*(const Real& c)
    const{
        /* Real r=c*(*this).getReal();
         Real i=c*(*this).getImm();
         dcomplex outCpx=dcomplex(c*(*this).getReal(),c*(*this).getImm());*/

        return dcomplex(c*(*this).getReal(),c*(*this).getImm());
    }
    dcomplex operator/(const Real& c)
    const{
//        Real tmp=1./c;
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
    dcomplex conj()
    {
        Real r=(*this).getReal();
        Real i=-(*this).getImm();
        dcomplex outCpx=dcomplex(r,-i);

        return outCpx;
    }

    friend dcomplex conj(const dcomplex& in)
    {
        Real r=(in).getReal();
        Real i=-(in).getImm();
        dcomplex outCpx=dcomplex(r,-i);

        return outCpx;
    }

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
        Real r1=std::exp(in.getReal());
        Real i1=in.getImm();

        return dcomplex(r1*std::cos(i1),r1*std::sin(i1));
    }

    friend dcomplex cos(const dcomplex& in)
    {
        Real r1=(in).getReal();
        Real i1=(in).getImm();
        Real r=std::cos(r1)*cosh(i1);
        Real i=std::sin(-r1)*sinh(i1);
        dcomplex outCpx=dcomplex(r,i);

        return outCpx;
    }

    friend dcomplex sin(const dcomplex& in)
    {
        Real r1=(in).getReal();
        Real i1=(in).getImm();
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

    dcomplex immUnit()
    {
        return (dcomplex(0.0,1.0));
    }
    friend void swap(dcomplex& a, dcomplex& b)
    {
        std::swap(a.re, b.re);
        std::swap(a.im, b.im);
    }
};


#endif //TESI_DCOMPLEX_H
