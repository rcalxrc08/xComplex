#include <cassert>
#include "acomplex.h"
#include "adept.h"
#include "gtest/gtest.h"
#include "functions.hpp"
#include <complex>
#define op operazione
#define Nprint 20
#define toll 1E-9

TEST(AComplexDerivative, log)
{
#undef op
#define op log
	double aa= (double)rand() / RAND_MAX;
	double bb= (double)rand() / RAND_MAX;
	adept::Stack s1;
	adept::adouble a=aa;
	adept::adouble b=bb;
	double a1=aa;
	double b1=bb;
	s1.new_recording();
	acomplex z=acomplex(a,b);
	std::complex<double> z1=std::complex<double>(a1,b1);
	double dx=toll;
	auto Dx=std::complex<double>(dx,0.0);
	double yDy=(op (z1+Dx)).real();
	double y=(op (z1)).real();
	double FDDer=(yDy-y)/dx;

	z  =op (z);
	z.getRealP().set_gradient(1.0);
	s1.reverse();
	double ADDer=a.get_gradient();
	double DerToll=toll*1000;
	EXPECT_NEAR(FDDer, ADDer,DerToll);
	if (HasFailure())
	{
		std::cout<<"SComplex: "<<std::setprecision(Nprint)<<FDDer<<std::endl;
		std::cout<<"AComplex: "<<std::setprecision(Nprint)<<a.get_gradient()<<std::endl;
	}
}

TEST(AComplexDerivative, sin)
{
#undef op
#define op sin
	double aa= (double)rand() / RAND_MAX;
	double bb= (double)rand() / RAND_MAX;
	adept::Stack s1;
	adept::adouble a=aa;
	adept::adouble b=bb;
	double a1=aa;
	double b1=bb;
	s1.new_recording();
	acomplex z=acomplex(a,b);
	std::complex<double> z1=std::complex<double>(a1,b1);
	double dx=toll;
	auto Dx=std::complex<double>(dx,0.0);
	double yDy=(op (z1+Dx)).real();
	double y=(op (z1)).real();
	double FDDer=(yDy-y)/dx;

	z  =op (z);
	z.getRealP().set_gradient(1.0);
	s1.reverse();
	double ADDer=a.get_gradient();
	double DerToll=toll*1000;
	EXPECT_NEAR(FDDer, ADDer,DerToll);
	if (HasFailure())
	{
		std::cout<<"SComplex: "<<std::setprecision(Nprint)<<FDDer<<std::endl;
		std::cout<<"AComplex: "<<std::setprecision(Nprint)<<a.get_gradient()<<std::endl;
	}
}

TEST(AComplexDerivative, cos)
{
#undef op
#define op cos
	double aa= (double)rand() / RAND_MAX;
	double bb= (double)rand() / RAND_MAX;
	adept::Stack s1;
	adept::adouble a=aa;
	adept::adouble b=bb;
	double a1=aa;
	double b1=bb;
	s1.new_recording();
	acomplex z=acomplex(a,b);
	std::complex<double> z1=std::complex<double>(a1,b1);
	double dx=toll;
	auto Dx=std::complex<double>(dx,0.0);
	double yDy=(op (z1+Dx)).real();
	double y=(op (z1)).real();
	double FDDer=(yDy-y)/dx;

	z  =op (z);
	z.getRealP().set_gradient(1.0);
	s1.reverse();
	double ADDer=a.get_gradient();
	double DerToll=toll*1000;
	EXPECT_NEAR(FDDer, ADDer,DerToll);
	if (HasFailure())
	{
		std::cout<<"SComplex: "<<std::setprecision(Nprint)<<FDDer<<std::endl;
		std::cout<<"AComplex: "<<std::setprecision(Nprint)<<a.get_gradient()<<std::endl;
	}
}

TEST(AComplexDerivative, tan)
{
#undef op
#define op tan
	double aa= (double)rand() / RAND_MAX;
	double bb= (double)rand() / RAND_MAX;
	adept::Stack s1;
	adept::adouble a=aa;
	adept::adouble b=bb;
	double a1=aa;
	double b1=bb;
	s1.new_recording();
	acomplex z=acomplex(a,b);
	std::complex<double> z1=std::complex<double>(a1,b1);
	double dx=toll;
	auto Dx=std::complex<double>(dx,0.0);
	double yDy=(op (z1+Dx)).real();
	double y=(op (z1)).real();
	double FDDer=(yDy-y)/dx;

	z  =op (z);
	z.getRealP().set_gradient(1.0);
	s1.reverse();
	double ADDer=a.get_gradient();
	double DerToll=toll*1000;
	EXPECT_NEAR(FDDer, ADDer,DerToll);
	if (HasFailure())
	{
		std::cout<<"SComplex: "<<std::setprecision(Nprint)<<FDDer<<std::endl;
		std::cout<<"AComplex: "<<std::setprecision(Nprint)<<a.get_gradient()<<std::endl;
	}
}
TEST(AComplexDerivative, exp)
{
#undef op
#define op exp
	double aa= (double)rand() / RAND_MAX;
	double bb= (double)rand() / RAND_MAX;
	adept::Stack s1;
	adept::adouble a=aa;
	adept::adouble b=bb;
	double a1=aa;
	double b1=bb;
	s1.new_recording();
	acomplex z=acomplex(a,b);
	std::complex<double> z1=std::complex<double>(a1,b1);
	double dx=toll;
	auto Dx=std::complex<double>(dx,0.0);
	double yDy=(op (z1+Dx)).real();
	double y=(op (z1)).real();
	double FDDer=(yDy-y)/dx;

	z  =op (z);
	z.getRealP().set_gradient(1.0);
	s1.reverse();
	double ADDer=a.get_gradient();
	double DerToll=toll*1000;
	EXPECT_NEAR(FDDer, ADDer,DerToll);
	if (HasFailure())
	{
		std::cout<<"SComplex: "<<std::setprecision(Nprint)<<FDDer<<std::endl;
		std::cout<<"AComplex: "<<std::setprecision(Nprint)<<a.get_gradient()<<std::endl;
	}
}

TEST(AComplexDerivative, mixed1)
{
#undef op
#define op exp(sin(log(cos
	double aa= (double)rand() / RAND_MAX;
	double bb= (double)rand() / RAND_MAX;
	adept::Stack s1;
	adept::adouble a=aa;
	adept::adouble b=bb;
	double a1=aa;
	double b1=bb;
	s1.new_recording();
	acomplex z=acomplex(a,b);
	std::complex<double> z1=std::complex<double>(a1,b1);
	double dx=toll;
	auto Dx=std::complex<double>(dx,0.0);
	double yDy=(op (z1+Dx))))).real();
	double y=(op (z1))))).real();
	double FDDer=(yDy-y)/dx;

	z  =op (z) )));
	z.getRealP().set_gradient(1.0);
	s1.reverse();
	double ADDer=a.get_gradient();
	double DerToll=toll*1000;
	std::cout<<"SComplex: "<<std::setprecision(Nprint)<<FDDer<<std::endl;
	std::cout<<"AComplex: "<<std::setprecision(Nprint)<<a.get_gradient()<<std::endl;
	EXPECT_NEAR(FDDer, ADDer,DerToll);
	if (HasFailure())
	{
		std::cout<<"SComplex: "<<std::setprecision(Nprint)<<FDDer<<std::endl;
		std::cout<<"AComplex: "<<std::setprecision(Nprint)<<a.get_gradient()<<std::endl;
	}
}

TEST(AComplexDerivative, mixed2)
{
#undef op
#define op exp(sin(sin(sin
	double aa= (double)rand() / RAND_MAX;
	double bb= (double)rand() / RAND_MAX;
	adept::Stack s1;
	adept::adouble a=aa;
	adept::adouble b=bb;
	double a1=aa;
	double b1=bb;
	s1.new_recording();
	acomplex z=acomplex(a,b);
	std::complex<double> z1=std::complex<double>(a1,b1);
	double dx=toll;
	auto Dx=std::complex<double>(dx,0.0);
	double yDy=(op (z1+Dx))))).real();
	double y=(op (z1))))).real();
	double FDDer=(yDy-y)/dx;

	z  =op (z) )));
	z.getRealP().set_gradient(1.0);
	s1.reverse();
	double ADDer=a.get_gradient();
	double DerToll=toll*1000;
	std::cout<<"SComplex: "<<std::setprecision(Nprint)<<FDDer<<std::endl;
	std::cout<<"AComplex: "<<std::setprecision(Nprint)<<a.get_gradient()<<std::endl;
	EXPECT_NEAR(FDDer, ADDer,DerToll);
	if (HasFailure())
	{
		std::cout<<"SComplex: "<<std::setprecision(Nprint)<<FDDer<<std::endl;
		std::cout<<"AComplex: "<<std::setprecision(Nprint)<<a.get_gradient()<<std::endl;
	}
}
