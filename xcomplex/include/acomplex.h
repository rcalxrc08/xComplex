//
// Created by nico on 1/25/17.
//

#ifndef TESI_ACOMPLEX_H
#define TESI_ACOMPLEX_H
#include <cmath>
#include <vector>
#include "adatan2.h"
#include "dcomplex.h"

#define ImagUnit "j"
//// All is passed by reference
class dcomplex;

class acomplex
{
/*    typedef adept::adouble AReal;
    typedef double Real;*/
private:
    AReal re;
    AReal im;
public:
    explicit acomplex () :re(),im(){}
    explicit acomplex (const AReal& RealP,const AReal& im) :re(RealP),im(im){}

    AReal getReal() const {return re;}

//    void setRealP(AReal& re) {acomplex::re = re;}

    AReal getImm() const {return im;}

//    void setim(AReal& im) {acomplex::im = im;}

    AReal getRho() const {return sqrt(re*re+im*im);}

    AReal getTheta() const {return adtan2(im,re);}

    AReal getNormSqr() const {return re*re+im*im;}

////Operators
    bool operator==(acomplex& o)
    {
        return ((*this).getImm()==o.getImm()&&(*this).getReal()==o.getReal());
    }

    bool operator!=(acomplex& o)
    {
        return !((*this)==o);
    }

////Mathematical Operators
    inline acomplex operator+(const AReal& cpx) //Adouble SUM
    const{
        /*AReal r=(*this).getReal()+cpx;
        AReal i=(*this).getImm();*/
//        acomplex outCpc=acomplex((*this).getReal()+cpx,(*this).getImm());

        return acomplex((*this).getReal()+cpx,(*this).getImm());
    }
    inline acomplex operator+(const Real& cpx) //Double SUM
    const{
        /* AReal r=(*this).getReal()+cpx;
         AReal i=(*this).getImm();
         acomplex outCpc=acomplex(r,i);*/

        return acomplex((*this).getReal()+cpx,(*this).getImm());
    }
    inline acomplex operator+(const acomplex& cpx) //Acomplex SUM
    const{
        /* AReal r = (*this).getReal() + cpx.getReal();
         AReal i = (*this).getImm() + cpx.getImm();
         acomplex outCpc = acomplex(r, i);*/

        return acomplex((*this).getReal() + cpx.getReal(),(*this).getImm() + cpx.getImm());
    }


    inline acomplex operator/(const Real& cpx)
    const{
        /*  AReal r=(*this).getReal();
          AReal i=(*this).getImm();
          acomplex outCpx=acomplex(r/cpx,i/cpx);
  */
        return acomplex((*this).getReal()/cpx,(*this).getImm()/cpx);
    }
    inline acomplex operator*(const AReal& cpx)
    const{
        /*AReal r=(*this).getReal();
        AReal i=(*this).getImm();
        acomplex outCpx=acomplex(r*cpx,i*cpx);*/

        return acomplex((*this).getReal()*cpx,(*this).getImm()*cpx);
    }
    inline acomplex operator/(const AReal& cpx)
    const{
        /*AReal r=(*this).getReal();
        AReal i=(*this).getImm();
        acomplex outCpx=acomplex(r/cpx,i/cpx);*/

        return acomplex((*this).getReal()/cpx,(*this).getImm()/cpx);
    }


    ////ADOUBLE DOUBLE
    friend acomplex operator+(Real c,const acomplex& in);
    friend acomplex operator*(Real c,const acomplex& in);
    friend acomplex operator/(Real c,const acomplex& in);
    friend acomplex operator-(Real c,const acomplex& in);

    friend acomplex operator+(const AReal& c,const acomplex& in);
    friend acomplex operator*(const AReal& c,const acomplex& in);
    friend acomplex operator/(const AReal& c,const acomplex& in);
    friend acomplex operator-(const AReal& c,const acomplex& in);

////Mixed Operators
    acomplex operator+(const dcomplex& cpx);////ADJ
    acomplex operator+=(const dcomplex& cpx);////ADJ
    acomplex operator-(const dcomplex& cpx);////ADJ
    acomplex operator-=(const dcomplex& cpx);////ADJ
    acomplex operator*(const dcomplex& cpx);////ADJ
    acomplex operator*=(const dcomplex& cpx);////ADJ
    acomplex operator/(const dcomplex& cpx);////ADJ
    acomplex operator/=(const dcomplex& cpx);////ADJ



    inline acomplex operator+=(const acomplex& cpx)
    {
        return (*this)+cpx;
    }

    inline acomplex operator-(const acomplex& cpx)
    {

//        acomplex outCpc=acomplex((*this).getReal()-cpx.getReal(),(*this).getImm()-cpx.getImm());

        return acomplex((*this).getReal()-cpx.getReal(),(*this).getImm()-cpx.getImm());;
    }
	inline acomplex operator-=(const AReal& cpx)
    {

//        acomplex outCpc=acomplex((*this).getReal()-cpx.getReal(),(*this).getImm()-cpx.getImm());

        return acomplex((*this).getReal()-cpx,(*this).getImm());;
    }
    inline acomplex operator-(const AReal& cpx)
    {

//        acomplex outCpc=acomplex((*this).getReal()-cpx,(*this).getImm());

        return acomplex((*this).getReal()-cpx,(*this).getImm());
    }

    inline acomplex operator-(const Real& cpx)
    {

//        acomplex outCpc=acomplex((*this).getReal()-cpx,(*this).getImm());

        return acomplex((*this).getReal()-cpx,(*this).getImm());
    }

    inline acomplex operator-=(const acomplex& cpx)
    {
        return (*this)-cpx;
    }

    inline acomplex operator*(const Real& cpx)
    {
        /*AReal r=(*this).getReal();
        AReal i=(*this).getImm();
        acomplex outCpx=acomplex(r*cpx,i*cpx);*/

        return acomplex((*this).getReal()*cpx,(*this).getImm()*cpx);
    }

    inline acomplex operator*(const acomplex& cpx)
    const{
        /*AReal r=(*this).getReal()*cpx.getReal()-(*this).getImm()*cpx.getImm();
        AReal i=(*this).getImm()*cpx.getReal()+(*this).getReal()*cpx.getImm();
        acomplex outCpx=acomplex((*this).getReal()*cpx.getReal()-(*this).getImm()*cpx.getImm(),(*this).getImm()*cpx.getReal()+(*this).getReal()*cpx.getImm());*/

        return acomplex((*this).getReal()*cpx.getReal()-(*this).getImm()*cpx.getImm(),(*this).getImm()*cpx.getReal()+(*this).getReal()*cpx.getImm());
    }

    inline acomplex operator*=(const acomplex& cpx)
    {
        return (*this)*cpx;
    }

    inline acomplex operator/(const acomplex& cpx)
    {
//        AReal r=((*this).getReal()*cpx.getReal()+(*this).getImm()*cpx.getImm());
//        AReal i=((*this).getImm()*cpx.getReal()-(*this).getReal()*cpx.getImm());
//        AReal Rho=cpx.getNormSqr();
//        acomplex outCpx=acomplex(((*this).getReal()*cpx.getReal()+(*this).getImm()*cpx.getImm())/cpx.getNormSqr(),((*this).getImm()*cpx.getReal()-(*this).getReal()*cpx.getImm())/cpx.getNormSqr());

        return acomplex(((*this).getReal()*cpx.getReal()+(*this).getImm()*cpx.getImm())/cpx.getNormSqr(),((*this).getImm()*cpx.getReal()-(*this).getReal()*cpx.getImm())/cpx.getNormSqr());
    }

    inline acomplex operator/=(const acomplex& cpx)
    {
        return (*this)/cpx;
    }

    friend std::ostream& operator<<(std::ostream& os, acomplex& obj)
    {
        Real tmp1=adept::value(-1.0*obj.getImm());
        if(obj.getImm()>=0.0)
            os<<obj.getReal()<<" + "<<ImagUnit<<" "<<obj.getImm();
        else
            os<<obj.getReal()<<" - "<<ImagUnit<<" "<<(tmp1);

        return os;
    }

////Mathematical Operations
    /*acomplex conj()
    {
        AReal r=(*this).getReal();
        AReal i=(*this).getImm();
        acomplex outCpx=acomplex(r,-1.*i);

        return outCpx;
    }

    friend acomplex conj(acomplex in)
    {
        AReal r=(in).getReal();
        AReal i=(in).getImm();
        acomplex outCpx=acomplex(r,-1.*i);

        return outCpx;
    }*/

    friend acomplex pow(const acomplex& in,const AReal& n)
    {
        /*AReal Rho=in.getRho();
        Rho=adept::pow(Rho,n);
        AReal Theta=n*in.getTheta();
        acomplex outCpx=acomplex(cos(Theta)*Rho,sin(Theta)*Rho);*/

        return acomplex(cos(n*in.getTheta())*pow(in.getRho(),n),sin(n*in.getTheta())*pow(in.getRho(),n));
    }

    friend acomplex pow(const acomplex& in,Real n)
    {
//        AReal Rho=adept::pow(in.getRho(),n);
//        Rho=adept::pow(Rho,n);
//        Rho=adept::pow(Rho,n);
//        AReal Theta=n*in.getTheta();
//        acomplex outCpx=acomplex(cos(n*in.getTheta())*adept::pow(in.getRho(),n),sin(n*in.getTheta())*adept::pow(in.getRho(),n));

        return acomplex(cos(n*in.getTheta())*pow(in.getRho(),n),sin(n*in.getTheta())*pow(in.getRho(),n));
    }

    friend acomplex exp(const acomplex& in)
    {
        /*AReal r1=exp(in.getReal());
        AReal i1=in.getImm();*/

        return acomplex(exp(in.getReal())*cos(in.getImm()),exp(in.getReal())*sin(in.getImm()));
    }

    friend acomplex cos(const acomplex& in)
    {
        /*AReal r1=(in).getReal();
        AReal i1=(in).getImm();*/
        /*    AReal r=cosh((in).getImm())*cos((in).getReal());
            AReal i=-1.*sin((in).getReal())*sinh((in).getImm());*/
//        acomplex outCpx=acomplex(cosh((in).getImm())*cos((in).getReal()),-1.*sin((in).getReal())*sinh((in).getImm()));

        return acomplex(cosh((in).getImm())*cos((in).getReal()),-1.*sin((in).getReal())*sinh((in).getImm()));
    }

    friend acomplex sin(const acomplex& in)
    {
//        using namespace adept;
        /* AReal r1=(in).getReal();
         AReal i1=(in).getImm();
         AReal r=sin((in).getReal())*cosh((in).getImm());
         AReal i=cos((in).getReal())*sinh((in).getImm());
         acomplex outCpx=acomplex(sin((in).getReal())*cosh((in).getImm()),cos((in).getReal())*sinh((in).getImm()));
 */
        return acomplex(sin((in).getReal())*cosh((in).getImm()),cos((in).getReal())*sinh((in).getImm()));
    }

    friend acomplex tan(const acomplex& in)
    {
        /*  auto tmp1=sin(in);
          auto tmp2=cos(in);
          acomplex outCpx=tmp1/tmp2;*/
//        return acomplex(  sin( 2.*in.getReal() ),  sinh( 2.*in.getImm())  )/  (  cos(2.*in.getReal())+cosh(2*in.getImm()));
        // return acomplex(  sin( 2.*in.getReal() ),  sinh( 2.*in.getImm())  )/  (  cos(2.*in.getReal())+cosh(2*in.getImm()));
        return sin(in)/cos(in);
    }

    friend acomplex log(const acomplex& in)
    {
        /*AReal r=log(in.getRho());
        AReal i=in.getTheta();
        acomplex outCpx=acomplex(log(in.getRho()),in.getTheta());*/

        return acomplex(log(in.getRho()),in.getTheta());
    }
    friend void swap(acomplex& a, acomplex& b)
    {

        std::swap(a.re, b.re);
        std::swap(a.im, b.im);
    }
    /*acomplex immUnit()
    {
        return (acomplex(0.0,1.0));
    }*/
};

////acomplex.cpp
inline acomplex operator+(Real c,const acomplex& in)
{
    return in+c;
}

inline acomplex operator-(Real c,const acomplex& in)
{
    return c+(-1.*in);
}

inline acomplex operator*(Real c,const acomplex& in)
{
    return in*c;
}

inline acomplex operator/(Real c,const acomplex& in)
{
//    AReal inv1=1./c;
    return in*(1./c);
}

inline acomplex operator+(const AReal& c,const acomplex& in)
{
    return in+c;
}
inline acomplex operator-(const AReal& c,const acomplex& in)
{
    return -1.*in+c;
}

inline acomplex operator*(const AReal& c,const acomplex& in)
{
    return in*c;
}

inline acomplex operator/(const AReal& c,const acomplex& in)
{
//    AReal inv1=1./c;
    return ((AReal)(1./c))*in;
}

#endif //TESI_ACOMPLEX_H
