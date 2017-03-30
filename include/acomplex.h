//
// Created by nico on 1/25/17.
//

#ifndef TESI_ACOMPLEX_H
#define TESI_ACOMPLEX_H
#include <cmath>
#include <vector>
#include <adept.h>
#include "adatan2.h"
#include "dcomplex.h"

#define ImagUnit "j"
//// All is passed by reference

class dcomplex;

class acomplex
{
    typedef adept::adouble AReal;

private:
    AReal realP;
    AReal immP;
public:
    explicit acomplex (const AReal& RealP=0.0,const AReal& ImmP=0.0) :realP(RealP),immP(ImmP){}

    AReal getRealP() const {return realP;}

//    void setRealP(AReal& real) {acomplex::realP = real;}

    AReal getImmP() const {return immP;}

//    void setImmP(AReal& immP) {acomplex::immP = immP;}

    AReal getRho() const {return sqrt(realP*realP+immP*immP);}

    AReal getTheta() const {return adtan2(immP,realP);}

    AReal getNormSqr() const {return realP*realP+immP*immP;}

////Operators
    bool operator==(acomplex& o)
    {
        return ((*this).getImmP()==o.getImmP()&&(*this).getRealP()==o.getRealP());
    }

    bool operator!=(acomplex& o)
    {
        return !((*this)==o);
    }

////Mathematical Operators
    inline acomplex operator+(const AReal& cpx) //Adouble SUM
    const{
        /*AReal r=(*this).getRealP()+cpx;
        AReal i=(*this).getImmP();*/
//        acomplex outCpc=acomplex((*this).getRealP()+cpx,(*this).getImmP());

        return acomplex((*this).getRealP()+cpx,(*this).getImmP());
    }
    inline acomplex operator+(const double& cpx) //Double SUM
    const{
        /* AReal r=(*this).getRealP()+cpx;
         AReal i=(*this).getImmP();
         acomplex outCpc=acomplex(r,i);*/

        return acomplex((*this).getRealP()+cpx,(*this).getImmP());
    }
    inline acomplex operator+(const acomplex& cpx) //Acomplex SUM
    const{
        /* AReal r = (*this).getRealP() + cpx.getRealP();
         AReal i = (*this).getImmP() + cpx.getImmP();
         acomplex outCpc = acomplex(r, i);*/

        return acomplex((*this).getRealP() + cpx.getRealP(),(*this).getImmP() + cpx.getImmP());
    }


    inline acomplex operator/(const double& cpx)
    const{
        /*  AReal r=(*this).getRealP();
          AReal i=(*this).getImmP();
          acomplex outCpx=acomplex(r/cpx,i/cpx);
  */
        return acomplex((*this).getRealP()/cpx,(*this).getImmP()/cpx);
    }
    inline acomplex operator*(const AReal& cpx)
    const{
        /*AReal r=(*this).getRealP();
        AReal i=(*this).getImmP();
        acomplex outCpx=acomplex(r*cpx,i*cpx);*/

        return acomplex((*this).getRealP()*cpx,(*this).getImmP()*cpx);
    }
    inline acomplex operator/(const AReal& cpx)
    const{
        /*AReal r=(*this).getRealP();
        AReal i=(*this).getImmP();
        acomplex outCpx=acomplex(r/cpx,i/cpx);*/

        return acomplex((*this).getRealP()/cpx,(*this).getImmP()/cpx);
    }


    ////ADOUBLE DOUBLE
    friend acomplex operator+(double c,const acomplex& in);
    friend acomplex operator*(double c,const acomplex& in);
    friend acomplex operator/(double c,const acomplex& in);
    friend acomplex operator-(double c,const acomplex& in);

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

//        acomplex outCpc=acomplex((*this).getRealP()-cpx.getRealP(),(*this).getImmP()-cpx.getImmP());

        return acomplex((*this).getRealP()-cpx.getRealP(),(*this).getImmP()-cpx.getImmP());;
    }
    inline acomplex operator-(const AReal& cpx)
    {

//        acomplex outCpc=acomplex((*this).getRealP()-cpx,(*this).getImmP());

        return acomplex((*this).getRealP()-cpx,(*this).getImmP());
    }

    inline acomplex operator-(const double& cpx)
    {

//        acomplex outCpc=acomplex((*this).getRealP()-cpx,(*this).getImmP());

        return acomplex((*this).getRealP()-cpx,(*this).getImmP());
    }

    inline acomplex operator-=(const acomplex& cpx)
    {
        return (*this)-cpx;
    }

    inline acomplex operator*(const double& cpx)
    {
        /*AReal r=(*this).getRealP();
        AReal i=(*this).getImmP();
        acomplex outCpx=acomplex(r*cpx,i*cpx);*/

        return acomplex((*this).getRealP()*cpx,(*this).getImmP()*cpx);
    }

    inline acomplex operator*(const acomplex& cpx)
    const{
        /*AReal r=(*this).getRealP()*cpx.getRealP()-(*this).getImmP()*cpx.getImmP();
        AReal i=(*this).getImmP()*cpx.getRealP()+(*this).getRealP()*cpx.getImmP();
        acomplex outCpx=acomplex((*this).getRealP()*cpx.getRealP()-(*this).getImmP()*cpx.getImmP(),(*this).getImmP()*cpx.getRealP()+(*this).getRealP()*cpx.getImmP());*/

        return acomplex((*this).getRealP()*cpx.getRealP()-(*this).getImmP()*cpx.getImmP(),(*this).getImmP()*cpx.getRealP()+(*this).getRealP()*cpx.getImmP());
    }

    inline acomplex operator*=(const acomplex& cpx)
    {
        return (*this)*cpx;
    }

    inline acomplex operator/(const acomplex& cpx)
    {
//        AReal r=((*this).getRealP()*cpx.getRealP()+(*this).getImmP()*cpx.getImmP());
//        AReal i=((*this).getImmP()*cpx.getRealP()-(*this).getRealP()*cpx.getImmP());
//        AReal Rho=cpx.getNormSqr();
//        acomplex outCpx=acomplex(((*this).getRealP()*cpx.getRealP()+(*this).getImmP()*cpx.getImmP())/cpx.getNormSqr(),((*this).getImmP()*cpx.getRealP()-(*this).getRealP()*cpx.getImmP())/cpx.getNormSqr());

        return acomplex(((*this).getRealP()*cpx.getRealP()+(*this).getImmP()*cpx.getImmP())/cpx.getNormSqr(),((*this).getImmP()*cpx.getRealP()-(*this).getRealP()*cpx.getImmP())/cpx.getNormSqr());
    }

    inline acomplex operator/=(const acomplex& cpx)
    {
        return (*this)/cpx;
    }

    friend std::ostream& operator<<(std::ostream& os, acomplex& obj)
    {
        AReal tmp1=-1.0*obj.getImmP();
        if(obj.getImmP()>=0.0)
            os<<obj.getRealP()<<" + "<<ImagUnit<<" "<<obj.getImmP();
        else
            os<<obj.getRealP()<<" - "<<ImagUnit<<" "<<(tmp1);

        return os;
    }

////Mathematical Operations
    /*acomplex conj()
    {
        AReal r=(*this).getRealP();
        AReal i=(*this).getImmP();
        acomplex outCpx=acomplex(r,-1.*i);

        return outCpx;
    }

    friend acomplex conj(acomplex in)
    {
        AReal r=(in).getRealP();
        AReal i=(in).getImmP();
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

    friend acomplex pow(const acomplex& in,double n)
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
        /*AReal r1=exp(in.getRealP());
        AReal i1=in.getImmP();*/

        return acomplex(exp(in.getRealP())*cos(in.getImmP()),exp(in.getRealP())*sin(in.getImmP()));
    }

    friend acomplex cos(const acomplex& in)
    {
        /*AReal r1=(in).getRealP();
        AReal i1=(in).getImmP();*/
        /*    AReal r=cosh((in).getImmP())*cos((in).getRealP());
            AReal i=-1.*sin((in).getRealP())*sinh((in).getImmP());*/
//        acomplex outCpx=acomplex(cosh((in).getImmP())*cos((in).getRealP()),-1.*sin((in).getRealP())*sinh((in).getImmP()));

        return acomplex(cosh((in).getImmP())*cos((in).getRealP()),-1.*sin((in).getRealP())*sinh((in).getImmP()));
    }

    friend acomplex sin(const acomplex& in)
    {
//        using namespace adept;
        /* AReal r1=(in).getRealP();
         AReal i1=(in).getImmP();
         AReal r=sin((in).getRealP())*cosh((in).getImmP());
         AReal i=cos((in).getRealP())*sinh((in).getImmP());
         acomplex outCpx=acomplex(sin((in).getRealP())*cosh((in).getImmP()),cos((in).getRealP())*sinh((in).getImmP()));
 */
        return acomplex(sin((in).getRealP())*cosh((in).getImmP()),cos((in).getRealP())*sinh((in).getImmP()));
    }

    friend acomplex tan(const acomplex& in)
    {
        /*  auto tmp1=sin(in);
          auto tmp2=cos(in);
          acomplex outCpx=tmp1/tmp2;*/
//        return acomplex(  sin( 2.*in.getRealP() ),  sinh( 2.*in.getImmP())  )/  (  cos(2.*in.getRealP())+cosh(2*in.getImmP()));
        return acomplex(  sin( 2.*in.getRealP() ),  sinh( 2.*in.getImmP())  )/  (  cos(2.*in.getRealP())+cosh(2*in.getImmP()));
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

        std::swap(a.realP, b.realP);
        std::swap(a.immP, b.immP);
    }
    /*acomplex immUnit()
    {
        return (acomplex(0.0,1.0));
    }*/
};

#endif //TESI_ACOMPLEX_H
