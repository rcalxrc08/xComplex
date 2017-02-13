#include <cassert>
#include "acomplex.h"
#include "adept.h"
#include "gtest/gtest.h"
#include "functions.hpp"
#include <complex>
#define op operazione
TEST(Five, BaseCase)
{
    ASSERT_EQ(5, five(0));
}

TEST(Five, MulBaseCase)
{
    ASSERT_EQ(5, five(1));
    ASSERT_EQ(5, five(2));
    ASSERT_EQ(5, five(3));
    ASSERT_EQ(5, five(4));
    ASSERT_EQ(5, five(5));
}
TEST(One, MulBaseCaseOne)
{
    ASSERT_EQ(1, one(1));
    ASSERT_EQ(1, one(2));
    ASSERT_EQ(1, one(3));
    ASSERT_EQ(1, one(4));
    ASSERT_EQ(1, one(5));
}
TEST(AComplex, timesEqual2)
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
}
TEST(AComplex, plusEqual)
{
#undef op
#define op +=
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
	z  =z+ z;
	z1 =z1+ z1;
	z.getRealP().set_gradient(1.0);
	s1.reverse();
	EXPECT_EQ(z1.real(), z.getRealP().value());
	EXPECT_EQ(z1.imag(), z.getImmP().value());
}
