#include <cassert>

#include "gtest/gtest.h"
#include "dcomplex.h"
#include "acomplex.h"
#include <cstdlib>
#include <complex>

#define op operazione
#define Nprint 20

TEST(DComplex, Zero)
{
	dcomplex x=dcomplex();
	EXPECT_EQ(0, x.getReal());
	if(HasFailure())
	{
		std::cout<<"Correggi Primo Test"<<std::endl;
	}
}
TEST(DComplex, One)
{
	dcomplex x=dcomplex(1.0);
	EXPECT_EQ(1.0, x.getReal());
}
TEST(DComplex, Assignment)
{
	double a= (double)rand() / RAND_MAX;
	double b= (double)rand() / RAND_MAX;
	dcomplex x=dcomplex(a,b);
	EXPECT_EQ(a, x.getReal());
	EXPECT_EQ(b, x.getImm());
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
	EXPECT_EQ(a+a1, y.getReal());
	EXPECT_EQ(b+b1, y.getImm());
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
	EXPECT_EQ(x1.real(), x.getReal());
	EXPECT_EQ(x1.imag(), x.getImm());
	if (HasFailure())
	{
		std::cout<<"Complex: "<<std::setprecision(Nprint)<<x1<<std::endl;
		std::cout<<"DComplex: "<<std::setprecision(Nprint)<<x<<std::endl;
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
	/*EXPECT_EQ(x1.real(), x.getReal());
    EXPECT_EQ(x1.imag(), x.getImm());*/
	double toll=1e-14;
	EXPECT_NEAR(x1.real(), x.getReal(),toll);
	EXPECT_NEAR(x1.imag(), x.getImm(),toll);
	if (HasFailure())
	{
		std::cout<<"Complex: "<<std::setprecision(Nprint)<<x1<<std::endl;
		std::cout<<"DComplex: "<<std::setprecision(Nprint)<<x<<std::endl;
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
	EXPECT_EQ(x1.real(), x.getReal());
	EXPECT_EQ(x1.imag(), x.getImm());
	if (HasFailure())
	{
		std::cout<<"Complex: "<<std::setprecision(Nprint)<<x1<<std::endl;
		std::cout<<"DComplex: "<<std::setprecision(Nprint)<<x<<std::endl;
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
	EXPECT_EQ(x1.real(), x.getReal());
	EXPECT_EQ(x1.imag(), x.getImm());
	if (HasFailure())
	{
		std::cout<<"Complex: "<<std::setprecision(Nprint)<<x1<<std::endl;
		std::cout<<"DComplex: "<<std::setprecision(Nprint)<<x<<std::endl;
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
	double toll=1e-14;
	EXPECT_NEAR(x1.real(), x.getReal(),toll);
	EXPECT_NEAR(x1.imag(), x.getImm(),toll);
	if (HasFailure())
	{
		std::cout<<"Complex: "<<std::setprecision(Nprint)<<x1<<std::endl;
		std::cout<<"DComplex: "<<std::setprecision(Nprint)<<x<<std::endl;
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
	double toll=1e-14;
	EXPECT_NEAR(x1.real(), x.getReal(),toll);
	EXPECT_NEAR(x1.imag(), x.getImm(),toll);
	if (HasFailure())
	{
		std::cout<<"Complex: "<<std::setprecision(Nprint)<<x1<<std::endl;
		std::cout<<"DComplex: "<<std::setprecision(Nprint)<<x<<std::endl;
	}
}
