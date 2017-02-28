#include <cassert>
#include "acomplex.h"
#include "adept.h"
#include "gtest/gtest.h"
#include "functions.hpp"
#include <complex>
#define op operazione
#define Nprint 20
#define toll1 1E-9
TEST(AComplex, plusScalar)
{
#undef op
#define op +
	double aa= (double)rand() / RAND_MAX;
	double bb= (double)rand() / RAND_MAX;
	adept::Stack s1;
	adept::adouble a=aa;
	adept::adouble b=bb;
	double a1=aa;
	double b1=bb;
	double cc= (double)rand() / RAND_MAX;
	s1.new_recording();
	acomplex z=acomplex(a,b);
	std::complex<double> z1=std::complex<double>(a1,b1);
	z  =z op cc;
	z1 =z1 op cc;
	z.getRealP().set_gradient(1.0);
	s1.reverse();
	EXPECT_EQ(z1.real(), z.getRealP().value());
	EXPECT_EQ(z1.imag(), z.getImmP().value());
	if (HasFailure())
	{
		std::cout<<"SComplex: "<<std::setprecision(Nprint)<<z<<std::endl;
		std::cout<<"AComplex: "<<std::setprecision(Nprint)<<z1<<std::endl;
	}
}

TEST(AComplex, minusScalar)
{
#undef op
#define op -
	double aa= (double)rand() / RAND_MAX;
	double bb= (double)rand() / RAND_MAX;
	adept::Stack s1;
	adept::adouble a=aa;
	adept::adouble b=bb;
	double a1=aa;
	double b1=bb;
	double cc= (double)rand() / RAND_MAX;
	s1.new_recording();
	acomplex z=acomplex(a,b);
	std::complex<double> z1=std::complex<double>(a1,b1);
	z  =z op cc;
	z1 =z1 op cc;
	z.getRealP().set_gradient(1.0);
	s1.reverse();
	EXPECT_EQ(z1.real(), z.getRealP().value());
	EXPECT_EQ(z1.imag(), z.getImmP().value());
	if (HasFailure())
	{
		std::cout<<"SComplex: "<<std::setprecision(Nprint)<<z<<std::endl;
		std::cout<<"AComplex: "<<std::setprecision(Nprint)<<z1<<std::endl;
	}
}

TEST(AComplex, multiplyScalar)
{
#undef op
#define op *
	double aa= (double)rand() / RAND_MAX;
	double bb= (double)rand() / RAND_MAX;
	adept::Stack s1;
	adept::adouble a=aa;
	adept::adouble b=bb;
	double a1=aa;
	double b1=bb;
	double cc= (double)rand() / RAND_MAX;
	s1.new_recording();
	acomplex z=acomplex(a,b);
	std::complex<double> z1=std::complex<double>(a1,b1);
	z  =z op cc;
	z1 =z1 op cc;
	z.getRealP().set_gradient(1.0);
	s1.reverse();
	EXPECT_EQ(z1.real(), z.getRealP().value());
	EXPECT_EQ(z1.imag(), z.getImmP().value());
	if (HasFailure())
	{
		std::cout<<"SComplex: "<<std::setprecision(Nprint)<<z<<std::endl;
		std::cout<<"AComplex: "<<std::setprecision(Nprint)<<z1<<std::endl;
	}
}
TEST(AComplex, divideScalar)
{
#undef op
#define op /
	double aa= (double)rand() / RAND_MAX;
	double bb= (double)rand() / RAND_MAX;
	adept::Stack s1;
	adept::adouble a=aa;
	adept::adouble b=bb;
	double a1=aa;
	double b1=bb;
	double cc= (double)rand() / RAND_MAX;
	s1.new_recording();
	acomplex z=acomplex(a,b);
	std::complex<double> z1=std::complex<double>(a1,b1);
	z  =z op cc;
	z1 =z1 op cc;
	z.getRealP().set_gradient(1.0);
	s1.reverse();
	EXPECT_EQ(z1.real(), z.getRealP().value());
	EXPECT_EQ(z1.imag(), z.getImmP().value());
	if (HasFailure())
	{
		std::cout<<"SComplex: "<<std::setprecision(Nprint)<<z<<std::endl;
		std::cout<<"AComplex: "<<std::setprecision(Nprint)<<z1<<std::endl;
	}
}

////SComplex Operations

TEST(AComplex, plus)
{
#undef op
#define op +
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
	z  =z op z;
	z1 =z1 op z1;
	z.getRealP().set_gradient(1.0);
	s1.reverse();
	EXPECT_EQ(z1.real(), z.getRealP().value());
	EXPECT_EQ(z1.imag(), z.getImmP().value());
	if (HasFailure())
	{
		std::cout<<"SComplex: "<<std::setprecision(Nprint)<<z<<std::endl;
		std::cout<<"AComplex: "<<std::setprecision(Nprint)<<z1<<std::endl;
	}
}

TEST(AComplex, multiplication)
{
#undef op
#define op *
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
	z =z op z;
	z1=z1 op z1;
	z.getRealP().set_gradient(1.0);
	s1.reverse();
	EXPECT_EQ(z1.real(), z.getRealP().value());
	EXPECT_EQ(z1.imag(), z.getImmP().value());
	if (HasFailure())
	{
		std::cout<<"SComplex: "<<std::setprecision(Nprint)<<z<<std::endl;
		std::cout<<"AComplex: "<<std::setprecision(Nprint)<<z1<<std::endl;
	}
}

TEST(AComplex, divide)
{
#undef op
#define op /
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
	z  =z op z;
	z1 =z1 op z1;
	z.getRealP().set_gradient(1.0);
	s1.reverse();
	EXPECT_EQ(z1.real(), z.getRealP().value());
	EXPECT_EQ(z1.imag(), z.getImmP().value());
	if (HasFailure())
	{
		std::cout<<"SComplex: "<<std::setprecision(Nprint)<<z<<std::endl;
		std::cout<<"AComplex: "<<std::setprecision(Nprint)<<z1<<std::endl;
	}
}

////Functions

TEST(AComplex, sin)
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
	z  = op (z);
	z1 = op (z1);
	z.getRealP().set_gradient(1.0);
	s1.reverse();
	EXPECT_EQ(z1.real(), z.getRealP().value());
	EXPECT_EQ(z1.imag(), z.getImmP().value());
	if (HasFailure())
	{
		std::cout<<"SComplex: "<<std::setprecision(Nprint)<<z<<std::endl;
		std::cout<<"AComplex: "<<std::setprecision(Nprint)<<z1<<std::endl;
	}
}
TEST(AComplex, cos)
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
	z  = op (z);
	z1 = op (z1);
	z.getRealP().set_gradient(1.0);
	s1.reverse();
	EXPECT_EQ(z1.real(), z.getRealP().value());
	EXPECT_EQ(z1.imag(), z.getImmP().value());
	if (HasFailure())
	{
		std::cout<<"SComplex: "<<std::setprecision(Nprint)<<z<<std::endl;
		std::cout<<"AComplex: "<<std::setprecision(Nprint)<<z1<<std::endl;
	}
}
TEST(AComplex, tan)
{
#undef op
#define op(N) tan(N)
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
	z  = op (z);
	z1 = op (z1);
	z.getRealP().set_gradient(1.0);
	s1.reverse();
	auto toll=1e-14;
	EXPECT_NEAR(z1.real(), z.getRealP().value(),toll);
	EXPECT_NEAR(z1.imag(), z.getImmP().value(),toll);
	if (HasFailure())
	{
		std::cout<<"SComplex: "<<std::setprecision(Nprint)<<z<<std::endl;
		std::cout<<"AComplex: "<<std::setprecision(Nprint)<<z1<<std::endl;
	}
}
TEST(AComplex, exp)
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
	z  = op (z);
	z1 = op (z1);
	z.getRealP().set_gradient(1.0);
	s1.reverse();
	EXPECT_EQ(z1.real(), z.getRealP().value());
	EXPECT_EQ(z1.imag(), z.getImmP().value());
	if (HasFailure())
	{
		std::cout<<"SComplex: "<<std::setprecision(Nprint)<<z<<std::endl;
		std::cout<<"AComplex: "<<std::setprecision(Nprint)<<z1<<std::endl;
	}
}
