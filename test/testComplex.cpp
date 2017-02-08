#include <cassert>

#include "gtest/gtest.h"
#include "functions.hpp"
#include "TestXComplex.h"
#include "dcomplex.h"
#include <cstdlib>
#include <complex>

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
TEST(DComplex, GenericRandom)
{
	double a= (double)rand() / RAND_MAX;
	double b= (double)rand() / RAND_MAX;
	dcomplex x=dcomplex(a,b);
    ASSERT_EQ(a, x.getRealP());
	ASSERT_EQ(b, x.getImmP());
}
TEST(DComplex, GenericSum)
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
TEST(DComplex, Exponential)
{
	double a= (double)rand() / RAND_MAX;
	double b= (double)rand() / RAND_MAX;
	dcomplex x=dcomplex(a,b);
	std::complex<double> x1=std::complex<double>(a,b);
	x=exp(x);
	x1=exp(x1);
    ASSERT_EQ(x1.real(), x.getRealP());
	ASSERT_EQ(x1.imag(), x.getImmP());
}
