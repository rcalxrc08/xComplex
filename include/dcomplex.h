//
// Created by nico on 1/25/17.
//

#ifndef TESI_DCOMPLEX_H
#define TESI_DCOMPLEX_H
#define ImagUnit "j"

////Include
#include <cmath>
#include <vector>
#include <adept.h>
#include "adatan2.h"
#include "acomplex.h"

class acomplex;

class dcomplex
{
private:
    double realP;
    double immP;
public:
    explicit dcomplex(const double& RealP=0.0,const double& ImmP=0.0):realP(RealP),immP(ImmP){}

    double getRealP() const{return realP;}

//    void setRealP(double& real) {realP = real;}

    double getImmP() const{return immP;}

//    void setImmP(double& imm) {immP = imm;}

    double getRho()const {return sqrt(realP*realP+immP*immP);}

    double getTheta()const {return atan2(immP,realP);}

    double getNormSqr() const{return realP*realP+immP*immP;}

////Direct Operators
    bool operator==(dcomplex& o)
    {
        return ((*this).getImmP()==o.getImmP()&&(*this).getRealP()==o.getRealP());
    }

    bool operator!=(dcomplex& o)
    {
        return !((*this)==o);
    }

    dcomplex operator+(const dcomplex& cpx)
    const {
        /*double r=(*this).getRealP()+cpx.getRealP();
        double i=(*this).getImmP()+cpx.getImmP();
        dcomplex outCpc=dcomplex(r,i);*/

        return dcomplex((*this).getRealP()+cpx.getRealP(),(*this).getImmP()+cpx.getImmP());
    }



    dcomplex operator+=(const dcomplex& cpx)
    const {
        return (*this)+cpx;
    }

    dcomplex operator-(const dcomplex& cpx)
    const {

//        dcomplex outCpc=dcomplex((*this).getRealP()-cpx.getRealP(),(*this).getImmP()-cpx.getImmP());

        return dcomplex((*this).getRealP()-cpx.getRealP(),(*this).getImmP()-cpx.getImmP());;
    }

    dcomplex operator-=(const dcomplex& cpx)
    const {
        return *this-cpx;
    }

    dcomplex operator*(const dcomplex& cpx)
    const{
        /*double r=(*this).getRealP()*cpx.getRealP()-(*this).getImmP()*cpx.getImmP();
        double i=(*this).getImmP()*cpx.getRealP()+(*this).getRealP()*cpx.getImmP();
        dcomplex outCpx=dcomplex(r,i);*/

        return dcomplex((*this).getRealP()*cpx.getRealP()-(*this).getImmP()*cpx.getImmP(),(*this).getImmP()*cpx.getRealP()+(*this).getRealP()*cpx.getImmP());
    }




    dcomplex operator*=(const dcomplex& cpx)
    const{
        return (*this)*cpx;
    }



    dcomplex operator/(const dcomplex& cpx)
    const{
        /*double r=((*this).getRealP()*cpx.getRealP()+(*this).getImmP()*cpx.getImmP());
        double i=((*this).getImmP()*cpx.getRealP()-(*this).getRealP()*cpx.getImmP());
        double Rho=cpx.getNormSqr();
        dcomplex outCpx=dcomplex(r/Rho,i/Rho);*/

        return dcomplex(((*this).getRealP()*cpx.getRealP()+(*this).getImmP()*cpx.getImmP())/cpx.getNormSqr(),((*this).getImmP()*cpx.getRealP()-(*this).getRealP()*cpx.getImmP())/cpx.getNormSqr());
    }


    dcomplex operator/=(const dcomplex& cpx)
    const{
        return (*this)/cpx;
    }

    friend std::ostream& operator<<(std::ostream& os, dcomplex& obj)
    {
        double tmp1=adept::value(-1.0*obj.getImmP());
        if(obj.getImmP()>=0.0)
            os<<obj.getRealP()<<" + "<<ImagUnit<<" "<<obj.getImmP()<<std::endl;
        else
            os<<obj.getRealP()<<" - "<<ImagUnit<<" "<<(tmp1)<<std::endl;

        return os;
    }
////Double Operators
    friend dcomplex operator+(double c,const dcomplex& in);
    friend dcomplex operator-(double c,const dcomplex& in);
    friend dcomplex operator*(double c,const dcomplex& in);
    friend dcomplex operator/(double c,const dcomplex& in);

    friend acomplex operator+(const adept::adouble& c,const dcomplex& in);
    friend acomplex operator-(const adept::adouble& c,const dcomplex& in);
    friend acomplex operator*(const adept::adouble& c,const dcomplex& in);
    friend acomplex operator/(const adept::adouble& c,const dcomplex& in);

    dcomplex operator+(const double& c)
    const{
       /* double r=c+(*this).getRealP();
        dcomplex outCpx=dcomplex(r,(*this).getImmP());*/

        return dcomplex(c+(*this).getRealP(),(*this).getImmP());
    }
    dcomplex operator-(const double& c)
    const{
        /*double r=(*this).getRealP()-c;
        dcomplex outCpx=dcomplex(r,(*this).getImmP());*/

        return dcomplex((*this).getRealP()-c,(*this).getImmP());
    }
    dcomplex operator*(const double& c)
    const{
       /* double r=c*(*this).getRealP();
        double i=c*(*this).getImmP();
        dcomplex outCpx=dcomplex(c*(*this).getRealP(),c*(*this).getImmP());*/

        return dcomplex(c*(*this).getRealP(),c*(*this).getImmP());
    }
    dcomplex operator/(const double& c)
    const{
//        double tmp=1./c;
        return (*this)*(1./c);
    }

    dcomplex operator+=(const double& num)
    const{
        return (*this)+num;
    }
    dcomplex operator-=(const double& num)
    const{
        return (*this)-num;
    }
    dcomplex operator*=(const double& num)
    const{
        return (*this)*num;
    }
    dcomplex operator/=(const double& num)
    const{
        return (*this)/num;
    }

////Mixed Operators
////Adouble

    acomplex operator*(const adept::adouble& c)const;////ADJ
    acomplex operator/(const adept::adouble& c)const;////ADJ
    acomplex operator+(const adept::adouble& c)const;////ADJ
    acomplex operator-(const adept::adouble& c)const;////ADJ
////Acomplex
    acomplex operator-(const acomplex& cpx)const;////ADJ
    acomplex operator+(const acomplex& cpx)const;////ADJ
    acomplex operator/(const acomplex& cpx)const;////ADJ
    acomplex operator*(const acomplex& cpx)const;////ADJ

////Mathematical Operations
    dcomplex conj()
    {
        double r=(*this).getRealP();
        double i=-(*this).getImmP();
        dcomplex outCpx=dcomplex(r,-i);

        return outCpx;
    }

    friend dcomplex conj(const dcomplex& in)
    {
        double r=(in).getRealP();
        double i=-(in).getImmP();
        dcomplex outCpx=dcomplex(r,-i);

        return outCpx;
    }

    friend dcomplex pow(const dcomplex& in,const double& n)
    {
        double Rho=in.getRho();
        Rho=std::pow(Rho,n);
        double Theta=n*in.getTheta();
        dcomplex outCpx=dcomplex(std::cos(Theta)*Rho,std::sin(Theta)*Rho);

        return outCpx;
    }

    friend dcomplex exp(const dcomplex& in)
    {
        double r1=std::exp(in.getRealP());
        double i1=in.getImmP();

        return dcomplex(r1*std::cos(i1),r1*std::sin(i1));
    }

    friend dcomplex cos(const dcomplex& in)
    {
        double r1=(in).getRealP();
        double i1=(in).getImmP();
        double r=std::cos(r1)*cosh(i1);
        double i=std::sin(-r1)*sinh(i1);
        dcomplex outCpx=dcomplex(r,i);

        return outCpx;
    }

    friend dcomplex sin(const dcomplex& in)
    {
        double r1=(in).getRealP();
        double i1=(in).getImmP();
        double r=std::sin(r1)*cosh(i1);
        double i=std::cos(r1)*sinh(i1);
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
        double r=std::log(in.getRho());
        double i=in.getTheta();
        dcomplex outCpx=dcomplex(r,i);

        return outCpx;
    }

    dcomplex immUnit()
    {
        return (dcomplex(0.0,1.0));
    }
};


#endif //TESI_DCOMPLEX_H
