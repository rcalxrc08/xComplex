#include <cassert>

#include "gtest/gtest.h"
#include "functions.hpp"
#include "TestXComplex.h"
#include "dcomplex.h"
#include <cstdlib>
#include <complex>
 
#define op operazione

TEST(DComplex, Zero)
{
	dcomplex x=dcomplex();
    ASSERT_EQ(0, x.getRealP());
}
TEST(DComplex, One)
{
	dcomplex x=dcomplex(1.0);
    ASSERT_EQ(1.0, x.getRealP());
}
TEST(DComplex, Assignment)
{
	double a= (double)rand() / RAND_MAX;
	double b= (double)rand() / RAND_MAX;
	dcomplex x=dcomplex(a,b);
    ASSERT_EQ(a, x.getRealP());
	ASSERT_EQ(b, x.getImmP());
}
TEST(DComplex, Sum)
{
	double a= (double)rand() / RAND_MAX;
	double b= (double)rand() / RAND_MAX;
	double a1= (double)rand() / RAND_MAX;
	double b1= (double)rand() / RAND_MAX;
	dcomplex x=dcomplex(a,b);
	dcomplex x1=dcomplex(a1,b1);
	dcomplex y=x+x1;
    ASSERT_EQ(a+a1, y.getRealP());
	ASSERT_EQ(b+b1, y.getImmP());
}
TEST(DComplex, exp)
{
#undef op
#define op exp
	double a= (double)rand() / RAND_MAX;
	double b= (double)rand() / RAND_MAX;
	dcomplex x=dcomplex(a,b);
	std::complex<double> x1=std::complex<double>(a,b);
	x=op (x);
	x1=op (x1);
    ASSERT_EQ(x1.real(), x.getRealP());
	ASSERT_EQ(x1.imag(), x.getImmP());
	if (HasFatalFailure())
	{
		std::cout<<"Complex: "<<std::setprecision(16)<<x1<<std::endl;
		std::cout<<"DComplex: "<<std::setprecision(16)<<x<<std::endl;
	}
}
TEST(DComplex, log)
{
#undef op
#define op log
	double a= (double)rand() / RAND_MAX;
	double b= (double)rand() / RAND_MAX;
	dcomplex x=dcomplex(a,b);
	std::complex<double> x1=std::complex<double>(a,b);
	x=op (x);
	x1=op (x1);
    ASSERT_EQ(x1.real(), x.getRealP());
	ASSERT_EQ(x1.imag(), x.getImmP());
	if (HasFatalFailure())
	{
		std::cout<<"Complex: "<<std::setprecision(16)<<x1<<std::endl;
		std::cout<<"DComplex: "<<std::setprecision(16)<<x<<std::endl;
	}
}
TEST(DComplex, sin)
{
#undef op
#define op sin
	double a= (double)rand() / RAND_MAX;
	double b= (double)rand() / RAND_MAX;
	dcomplex x=dcomplex(a,b);
	std::complex<double> x1=std::complex<double>(a,b);
	x=op (x);
	x1=op (x1);
    ASSERT_EQ(x1.real(), x.getRealP());
	ASSERT_EQ(x1.imag(), x.getImmP());
	if (HasFatalFailure())
	{
		std::cout<<"Complex: "<<std::setprecision(16)<<x1<<std::endl;
		std::cout<<"DComplex: "<<std::setprecision(16)<<x<<std::endl;
	}
}
TEST(DComplex, cos)
{
#undef op
#define op cos
	double a= (double)rand() / RAND_MAX;
	double b= (double)rand() / RAND_MAX;
	dcomplex x=dcomplex(a,b);
	std::complex<double> x1=std::complex<double>(a,b);
	x=op (x);
	x1=op (x1);
    ASSERT_EQ(x1.real(), x.getRealP());
	ASSERT_EQ(x1.imag(), x.getImmP());
	if (HasFatalFailure())
	{
		std::cout<<"Complex: "<<std::setprecision(16)<<x1<<std::endl;
		std::cout<<"DComplex: "<<std::setprecision(16)<<x<<std::endl;
	}
}
TEST(DComplex, tan)
{
#undef op
#define op tan
	double a= (double)rand() / RAND_MAX;
	double b= (double)rand() / RAND_MAX;
	dcomplex x=dcomplex(a,b);
	std::complex<double> x1=std::complex<double>(a,b);
	x=op (x);
	x1=op (x1);
    ASSERT_EQ(x1.real(), x.getRealP());
	ASSERT_EQ(x1.imag(), x.getImmP());
	if (HasFatalFailure())
	{
		std::cout<<"Complex: "<<std::setprecision(16)<<x1<<std::endl;
		std::cout<<"DComplex: "<<std::setprecision(16)<<x<<std::endl;
	}
}
TEST(DComplex, pow)
{
#undef op
#define op pow
	double a= (double)rand() / RAND_MAX;
	double b= (double)rand() / RAND_MAX;
	double n= (double)rand() / RAND_MAX;
	dcomplex x=dcomplex(a,b);
	std::complex<double> x1=std::complex<double>(a,b);
	x=op (x,n);
	x1=op (x1,n);
    ASSERT_EQ(x1.real(), x.getRealP());
	ASSERT_EQ(x1.imag(), x.getImmP());
	if (HasFatalFailure())
	{
		std::cout<<"Complex: "<<std::setprecision(16)<<x1<<std::endl;
		std::cout<<"DComplex: "<<std::setprecision(16)<<x<<std::endl;
	}
}
