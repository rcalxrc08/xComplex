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

private:
    adept::adouble realP;
    adept::adouble immP;
public:
    explicit acomplex (const adept::adouble& RealP=0.0,const adept::adouble& ImmP=0.0) :realP(RealP),immP(ImmP){}

    adept::adouble getRealP() const {return realP;}

//    void setRealP(adept::adouble& real) {acomplex::realP = real;}

    adept::adouble getImmP() const {return immP;}

//    void setImmP(adept::adouble& immP) {acomplex::immP = immP;}

    adept::adouble getRho() const {return sqrt(realP*realP+immP*immP);}

    adept::adouble getTheta() const {return adtan2(immP,realP);}

    adept::adouble getNormSqr() const {return realP*realP+immP*immP;}

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
    acomplex operator+(const adept::adouble& cpx) //Adouble SUM
    const{
        /*adept::adouble r=(*this).getRealP()+cpx;
        adept::adouble i=(*this).getImmP();*/
//        acomplex outCpc=acomplex((*this).getRealP()+cpx,(*this).getImmP());

        return acomplex((*this).getRealP()+cpx,(*this).getImmP());
    }
    acomplex operator+(const double& cpx) //Double SUM
    const{
       /* adept::adouble r=(*this).getRealP()+cpx;
        adept::adouble i=(*this).getImmP();
        acomplex outCpc=acomplex(r,i);*/

        return acomplex((*this).getRealP()+cpx,(*this).getImmP());
    }
    acomplex operator+(const acomplex& cpx) //Acomplex SUM
    const{
       /* adept::adouble r = (*this).getRealP() + cpx.getRealP();
        adept::adouble i = (*this).getImmP() + cpx.getImmP();
        acomplex outCpc = acomplex(r, i);*/

        return acomplex((*this).getRealP() + cpx.getRealP(),(*this).getImmP() + cpx.getImmP());
    }


    acomplex operator/(const double& cpx)
    const{
      /*  adept::adouble r=(*this).getRealP();
        adept::adouble i=(*this).getImmP();
        acomplex outCpx=acomplex(r/cpx,i/cpx);
*/
        return acomplex((*this).getRealP()/cpx,(*this).getImmP()/cpx);
    }
    acomplex operator*(const adept::adouble& cpx)
    const{
        /*adept::adouble r=(*this).getRealP();
        adept::adouble i=(*this).getImmP();
        acomplex outCpx=acomplex(r*cpx,i*cpx);*/

        return acomplex((*this).getRealP()*cpx,(*this).getImmP()*cpx);
    }
    acomplex operator/(const adept::adouble& cpx)
    const{
        /*adept::adouble r=(*this).getRealP();
        adept::adouble i=(*this).getImmP();
        acomplex outCpx=acomplex(r/cpx,i/cpx);*/

        return acomplex((*this).getRealP()/cpx,(*this).getImmP()/cpx);
    }


    ////ADOUBLE DOUBLE
    friend acomplex operator+(double c,const acomplex& in);
    friend acomplex operator*(double c,const acomplex& in);
    friend acomplex operator/(double c,const acomplex& in);
    friend acomplex operator-(double c,const acomplex& in);

    friend acomplex operator+(const adept::adouble& c,const acomplex& in);
    friend acomplex operator*(const adept::adouble& c,const acomplex& in);
    friend acomplex operator/(const adept::adouble& c,const acomplex& in);
    friend acomplex operator-(const adept::adouble& c,const acomplex& in);

////Mixed Operators
    acomplex operator+(const dcomplex& cpx);////ADJ
    acomplex operator+=(const dcomplex& cpx);////ADJ
    acomplex operator-(const dcomplex& cpx);////ADJ
    acomplex operator-=(const dcomplex& cpx);////ADJ
    acomplex operator*(const dcomplex& cpx);////ADJ
    acomplex operator*=(const dcomplex& cpx);////ADJ
    acomplex operator/(const dcomplex& cpx);////ADJ
    acomplex operator/=(const dcomplex& cpx);////ADJ



    acomplex operator+=(const acomplex& cpx)
    {
        return (*this)+cpx;
    }

    acomplex operator-(const acomplex& cpx)
    {

//        acomplex outCpc=acomplex((*this).getRealP()-cpx.getRealP(),(*this).getImmP()-cpx.getImmP());

        return acomplex((*this).getRealP()-cpx.getRealP(),(*this).getImmP()-cpx.getImmP());;
    }
    acomplex operator-(const adept::adouble& cpx)
    {

//        acomplex outCpc=acomplex((*this).getRealP()-cpx,(*this).getImmP());

        return acomplex((*this).getRealP()-cpx,(*this).getImmP());
    }

    acomplex operator-(const double& cpx)
    {

//        acomplex outCpc=acomplex((*this).getRealP()-cpx,(*this).getImmP());

        return acomplex((*this).getRealP()-cpx,(*this).getImmP());
    }

    acomplex operator-=(const acomplex& cpx)
    {
        return (*this)-cpx;
    }

    acomplex operator*(const double& cpx)
    {
        /*adept::adouble r=(*this).getRealP();
        adept::adouble i=(*this).getImmP();
        acomplex outCpx=acomplex(r*cpx,i*cpx);*/

        return acomplex((*this).getRealP()*cpx,(*this).getImmP()*cpx);
    }

    acomplex operator*(const acomplex& cpx)
    const{
        /*adept::adouble r=(*this).getRealP()*cpx.getRealP()-(*this).getImmP()*cpx.getImmP();
        adept::adouble i=(*this).getImmP()*cpx.getRealP()+(*this).getRealP()*cpx.getImmP();
        acomplex outCpx=acomplex((*this).getRealP()*cpx.getRealP()-(*this).getImmP()*cpx.getImmP(),(*this).getImmP()*cpx.getRealP()+(*this).getRealP()*cpx.getImmP());*/

        return acomplex((*this).getRealP()*cpx.getRealP()-(*this).getImmP()*cpx.getImmP(),(*this).getImmP()*cpx.getRealP()+(*this).getRealP()*cpx.getImmP());
    }

    acomplex operator*=(const acomplex& cpx)
    {
        return (*this)*cpx;
    }

    acomplex operator/(const acomplex& cpx)
    {
//        adept::adouble r=((*this).getRealP()*cpx.getRealP()+(*this).getImmP()*cpx.getImmP());
//        adept::adouble i=((*this).getImmP()*cpx.getRealP()-(*this).getRealP()*cpx.getImmP());
//        adept::adouble Rho=cpx.getNormSqr();
//        acomplex outCpx=acomplex(((*this).getRealP()*cpx.getRealP()+(*this).getImmP()*cpx.getImmP())/cpx.getNormSqr(),((*this).getImmP()*cpx.getRealP()-(*this).getRealP()*cpx.getImmP())/cpx.getNormSqr());

        return acomplex(((*this).getRealP()*cpx.getRealP()+(*this).getImmP()*cpx.getImmP())/cpx.getNormSqr(),((*this).getImmP()*cpx.getRealP()-(*this).getRealP()*cpx.getImmP())/cpx.getNormSqr());
    }

    acomplex operator/=(const acomplex& cpx)
    {
        return (*this)/cpx;
    }

    friend std::ostream& operator<<(std::ostream& os, acomplex& obj)
    {
        adept::adouble tmp1=adept::value(-1.0*obj.getImmP());
        if(obj.getImmP()>=0.0)
            os<<obj.getRealP()<<" + "<<ImagUnit<<" "<<obj.getImmP();
        else
            os<<obj.getRealP()<<" - "<<ImagUnit<<" "<<(tmp1);

        return os;
    }

////Mathematical Operations
    /*acomplex conj()
    {
        adept::adouble r=(*this).getRealP();
        adept::adouble i=(*this).getImmP();
        acomplex outCpx=acomplex(r,-1.*i);

        return outCpx;
    }

    friend acomplex conj(acomplex in)
    {
        adept::adouble r=(in).getRealP();
        adept::adouble i=(in).getImmP();
        acomplex outCpx=acomplex(r,-1.*i);

        return outCpx;
    }*/

    friend acomplex pow(const acomplex& in,const adept::adouble& n)
    {
        /*adept::adouble Rho=in.getRho();
        Rho=adept::pow(Rho,n);
        adept::adouble Theta=n*in.getTheta();
        acomplex outCpx=acomplex(cos(Theta)*Rho,sin(Theta)*Rho);*/

        return acomplex(cos(n*in.getTheta())*adept::pow(in.getRho(),n),sin(n*in.getTheta())*adept::pow(in.getRho(),n));
    }

    friend acomplex pow(const acomplex& in,double n)
    {
//        adept::adouble Rho=adept::pow(in.getRho(),n);
//        Rho=adept::pow(Rho,n);
//        Rho=adept::pow(Rho,n);
//        adept::adouble Theta=n*in.getTheta();
//        acomplex outCpx=acomplex(cos(n*in.getTheta())*adept::pow(in.getRho(),n),sin(n*in.getTheta())*adept::pow(in.getRho(),n));

        return acomplex(cos(n*in.getTheta())*adept::pow(in.getRho(),n),sin(n*in.getTheta())*adept::pow(in.getRho(),n));
    }

    friend acomplex exp(const acomplex& in)
    {
        /*adept::adouble r1=exp(in.getRealP());
        adept::adouble i1=in.getImmP();*/

        return acomplex(exp(in.getRealP())*cos(in.getImmP()),exp(in.getRealP())*sin(in.getImmP()));
    }

    friend acomplex cos(const acomplex& in)
    {
        /*adept::adouble r1=(in).getRealP();
        adept::adouble i1=(in).getImmP();*/
    /*    adept::adouble r=cosh((in).getImmP())*cos((in).getRealP());
        adept::adouble i=-1.*sin((in).getRealP())*sinh((in).getImmP());*/
//        acomplex outCpx=acomplex(cosh((in).getImmP())*cos((in).getRealP()),-1.*sin((in).getRealP())*sinh((in).getImmP()));

        return acomplex(cosh((in).getImmP())*cos((in).getRealP()),-1.*sin((in).getRealP())*sinh((in).getImmP()));
    }

    friend acomplex sin(const acomplex& in)
    {
//        using namespace adept;
       /* adept::adouble r1=(in).getRealP();
        adept::adouble i1=(in).getImmP();
        adept::adouble r=sin((in).getRealP())*cosh((in).getImmP());
        adept::adouble i=cos((in).getRealP())*sinh((in).getImmP());
        acomplex outCpx=acomplex(sin((in).getRealP())*cosh((in).getImmP()),cos((in).getRealP())*sinh((in).getImmP()));
*/
        return acomplex(sin((in).getRealP())*cosh((in).getImmP()),cos((in).getRealP())*sinh((in).getImmP()));
    }

    friend acomplex tan(const acomplex& in)
    {
      /*  auto tmp1=sin(in);
        auto tmp2=cos(in);
        acomplex outCpx=tmp1/tmp2;*/

        return sin(in)/cos(in);
    }

    friend acomplex log(const acomplex& in)
    {
        /*adept::adouble r=log(in.getRho());
        adept::adouble i=in.getTheta();
        acomplex outCpx=acomplex(log(in.getRho()),in.getTheta());*/

        return acomplex(log(in.getRho()),in.getTheta());
    }

    acomplex immUnit()
    {
        return (acomplex(0.0,1.0));
    }
};

#endif //TESI_ACOMPLEX_H
