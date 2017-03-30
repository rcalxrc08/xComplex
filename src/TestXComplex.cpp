//
// Created by nico on 1/23/17.
//
#include <adept.h>
#include "TestXComplex.h"
#include "../xcomplex/Include/acomplex.h"
#include "../xcomplex/Include/dcomplex.h"
#include <iomanip>
#include <utility>

#define Lprint std::cout<<std::endl<<
#define Rprint <<std::endl;
#define aa -10.0
#define bb -0.5

//typedef xcomplex<adept::adouble> acomplex;
//typedef xcomplex<double> dcomplex;

std::pair<double,double> matPowTest() ////PASSATO
{
    Lprint "Testing Pow Function" Rprint
    adept::Stack s1;
    adept::adouble a = aa;
    adept::adouble b = bb;
    s1.new_recording();
    acomplex x = acomplex(a, b);
    acomplex r = pow(x, 3.5);
    std::cout<<std::setprecision(20) << r << std::endl;
    auto y1 = r.getRealP();
    adept::adouble y = y1;
    std::cout << "Value: " << y << std::endl;
    y.set_gradient(1.0);
    s1.reverse();
    std::cout << "Derivative wrt RealPart: " << a.get_gradient() << std::endl;
    std::cout << "Derivative wrt ImgPart: " << b.get_gradient() << std::endl;
	std::pair<double,double> out=std::pair<double,double>();
	out.first=a.get_gradient();
	out.second=b.get_gradient();
	return out;
}

std::pair<double,double> matSinTest() ////PASSATO
{
    Lprint "Testing Sine Function" Rprint
    adept::Stack s1;
    adept::adouble a = aa;
    adept::adouble b = bb;
    s1.new_recording();
    acomplex x = acomplex(a, b);
//    x=x*a;
    auto r = sin(x);//o SinTry2 stessa cosa!
    std::cout << r << std::endl;
    auto y1 = r.getRealP();
    adept::adouble y = y1;
    std::cout << "Value: " << y << std::endl;
    y.set_gradient(1.0);
    s1.reverse();
    std::cout << "Derivative wrt RealPart: " << a.get_gradient() << std::endl;
    std::cout << "Derivative wrt ImgPart: " << b.get_gradient() << std::endl;
	std::pair<double,double> out=std::pair<double,double>();
	out.first=a.get_gradient();
	out.second=b.get_gradient();
	return out;
}

std::pair<double,double> matCosTest() ////PASSATO
{
    Lprint "Testing Cosine Function" Rprint
    adept::Stack s1;
    adept::adouble a = aa;
    adept::adouble b = bb;
    s1.new_recording();
    acomplex x = acomplex(a, b);
    auto r = cos(x);//o cosTry2 stessa cosa!
    std::cout << r << std::endl;
    auto y1 = r.getRealP();
    adept::adouble y = y1;
    std::cout << "Value: " << y << std::endl;
    y.set_gradient(1.0);
    s1.reverse();
    std::cout << "Derivative wrt RealPart: " << a.get_gradient() << std::endl;
    std::cout << "Derivative wrt ImgPart: " << b.get_gradient() << std::endl;
	std::pair<double,double> out=std::pair<double,double>();
	out.first=a.get_gradient();
	out.second=b.get_gradient();
	return out;
}

std::pair<double,double> matTanTest() ////PASSATO
{
    Lprint "Testing Tan Function" Rprint
    adept::Stack s1;
    adept::adouble a = aa;
    adept::adouble b = bb;
    s1.new_recording();
    acomplex x = acomplex(a, b);
    auto r = tan(x);
    std::cout << r << std::endl;
    auto y1 = r.getRealP();
    adept::adouble y = y1;
    std::cout << "Value: " << y << std::endl;
    y.set_gradient(1.0);
    s1.reverse();
    std::cout << "Derivative wrt RealPart: " << a.get_gradient() << std::endl;
    std::cout << "Derivative wrt ImgPart: " << b.get_gradient() << std::endl;
	std::pair<double,double> out=std::pair<double,double>();
	out.first=a.get_gradient();
	out.second=b.get_gradient();
	return out;
}

std::pair<double,double> matATanTest() ////PASSATO
{
    Lprint "Testing ATan Function" Rprint
    adept::Stack s1;
    adept::adouble a = aa;
    adept::adouble b = bb;
    s1.new_recording();
    acomplex x = acomplex(a, b);
    auto r = x.getTheta();
    std::cout << r << std::endl;
    auto y1 = r;
    adept::adouble y = y1;
    std::cout << "Value: " << y << std::endl;
    y.set_gradient(1.0);
    s1.reverse();
    std::cout << "Derivative wrt RealPart: " << a.get_gradient() << std::endl;
    std::cout << "Derivative wrt ImgPart: " << b.get_gradient() << std::endl;
	std::pair<double,double> out=std::pair<double,double>();
	out.first=a.get_gradient();
	out.second=b.get_gradient();
	return out;
}

std::pair<double,double> matExpTest() ////PASSATO
{
    Lprint "Testing Exp Function" Rprint
    adept::Stack s1;
    adept::adouble a = aa;
    adept::adouble b = bb;
    s1.new_recording();
    acomplex x = acomplex(a, b);
    acomplex r = exp(x);//o expTry2 stessa cosa!
    std::cout << r << std::endl;
    auto y1 = r.getRealP();
    adept::adouble y = y1;
    std::cout << "Value: " << y << std::endl;
    y.set_gradient(1.0);
    s1.reverse();
    std::cout << "Derivative wrt RealPart: " << a.get_gradient() << std::endl;
    std::cout << "Derivative wrt ImgPart: " << b.get_gradient() << std::endl;
	std::pair<double,double> out=std::pair<double,double>();
	out.first=a.get_gradient();
	out.second=b.get_gradient();
	return out;
}

std::pair<double,double> matLogTest() ////PASSATO
{
    Lprint "Testing Log Function" Rprint
    adept::Stack s1;
    adept::adouble a = aa;
    adept::adouble b = bb;
    s1.new_recording();
    acomplex x = acomplex(a, b);
    auto r = log(x);
    std::cout << r << std::endl;
    auto y1 = r.getRealP();
    adept::adouble y = y1;
    std::cout << "Value: " << y << std::endl;
    y.set_gradient(1.0);
    s1.reverse();
    std::cout << "Derivative wrt RealPart: " << a.get_gradient() << std::endl;
    std::cout << "Derivative wrt ImgPart: " << b.get_gradient() << std::endl;
	std::pair<double,double> out=std::pair<double,double>();
	out.first=a.get_gradient();
	out.second=b.get_gradient();
	return out;
}

std::pair<double,double> matMixTest()////PASSATO
{
    Lprint "Testing Mixed Function" Rprint
    adept::Stack s1;
    adept::adouble a = aa;
    adept::adouble b = bb;
    s1.new_recording();
    acomplex x = acomplex(a, b);
    //auto p1=complex (1.0,0.0);
    auto r = log(x);
    r = cos(r);
    r = exp(r);
    r = sin(r);
    r = tan(r);
    r = sin(tan(r)) ;//Finally Works
    std::cout << r << std::endl;
    auto y1 = r.getRealP();
    adept::adouble y = y1;
    std::cout << "Value: " << y << std::endl;
    y.set_gradient(1.0);
    s1.reverse();
    std::cout << "Derivative wrt RealPart: " << a.get_gradient() << std::endl;
    std::cout << "Derivative wrt ImgPart: " << b.get_gradient() << std::endl;
	std::pair<double,double> out=std::pair<double,double>();
	out.first=a.get_gradient();
	out.second=b.get_gradient();
	return out;
}



void easyTestRunner() {
    matPowTest();////Passed
    matSinTest();////Passed
    matCosTest();////Passed
    matTanTest();////Passed
    matATanTest();////Passed
    matExpTest();////Passed
    matLogTest();////Passed
    matMixTest();////Passed
}
