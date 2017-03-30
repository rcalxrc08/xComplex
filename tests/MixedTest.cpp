#include <cassert>
#include "../xcomplex/Include/acomplex.h"
#include "../Adept/adept.h"
#include "gtest/gtest.h"
#include <complex>
#define op operazione
#define Nprint 20
#define toll1 1E-9
TEST(AComplexMixed, plusScalarMixControl)
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
    dcomplex z1=dcomplex(a1,b1);
    s1.new_recording();
    acomplex z=acomplex(a,b);
    z  =z op cc;
    z+=z;
    z1 =z1 op cc;
    z1+=z1;
    acomplex res=z-z1;
    z.getReal().set_gradient(1.0);
    s1.reverse();
    EXPECT_EQ(res.getReal().value(),0.0);
    EXPECT_EQ(res.getImm().value(),0.0);
    if (HasFailure())
    {
        std::cout<<"SComplex: "<<std::setprecision(Nprint)<<z<<std::endl;
        std::cout<<"AComplex: "<<std::setprecision(Nprint)<<z1<<std::endl;
    }
}

TEST(AComplexMixed, minusScalarMixControl)
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
    dcomplex z1=dcomplex(a1,b1);
    s1.new_recording();
    acomplex z=acomplex(a,b);
    z  =z op cc;
    z1 =z1 op cc;
    acomplex res=z-z1;
    z.getReal().set_gradient(1.0);
    s1.reverse();
    EXPECT_EQ(res.getReal().value(),0.0);
    EXPECT_EQ(res.getImm().value(),0.0);
    if (HasFailure())
    {
        std::cout<<"SComplex: "<<std::setprecision(Nprint)<<z<<std::endl;
        std::cout<<"AComplex: "<<std::setprecision(Nprint)<<z1<<std::endl;
    }
}

TEST(AComplexMixed, multiplyScalarMixControl)
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
    dcomplex z1=dcomplex(a1,b1);
    s1.new_recording();
    acomplex z=acomplex(a,b);
    z  =z op cc;
    z1 =z1 op cc;
    acomplex res=z-z1;
    z.getReal().set_gradient(1.0);
    s1.reverse();
    EXPECT_EQ(res.getReal().value(),0.0);
    EXPECT_EQ(res.getImm().value(),0.0);
    if (HasFailure())
    {
        std::cout<<"SComplex: "<<std::setprecision(Nprint)<<z<<std::endl;
        std::cout<<"AComplex: "<<std::setprecision(Nprint)<<z1<<std::endl;
    }
}
TEST(AComplexMixed, divideScalarMixControl)
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
    dcomplex z1=dcomplex(a1,b1);
    s1.new_recording();
    acomplex z=acomplex(a,b);
    z  =z op cc;
    z1 =z1 op cc;
    acomplex res=z-z1;
    z.getReal().set_gradient(1.0);
    s1.reverse();
    EXPECT_EQ(res.getReal().value(),0.0);
    EXPECT_EQ(res.getImm().value(),0.0);
    if (HasFailure())
    {
        std::cout<<"SComplex: "<<std::setprecision(Nprint)<<z<<std::endl;
        std::cout<<"AComplex: "<<std::setprecision(Nprint)<<z1<<std::endl;
    }
}

////SComplex Operations

TEST(AComplexMixed, plusMixControl)
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
    dcomplex z1=dcomplex(a1,b1);
    s1.new_recording();
    acomplex z=acomplex(a,b);
    z  =z op cc;
    z1 =z1 op cc;
    acomplex res=z-z1;
    z.getReal().set_gradient(1.0);
    s1.reverse();
    EXPECT_EQ(res.getReal().value(),0.0);
    EXPECT_EQ(res.getImm().value(),0.0);
    if (HasFailure())
    {
        std::cout<<"SComplex: "<<std::setprecision(Nprint)<<z<<std::endl;
        std::cout<<"AComplex: "<<std::setprecision(Nprint)<<z1<<std::endl;
    }
}

TEST(AComplexMixed, multiplicationMixControl)
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
    dcomplex z1=dcomplex(a1,b1);
    s1.new_recording();
    acomplex z=acomplex(a,b);
    z  =z op cc;
    z*=z1;
    z1*=z1;
    z1 =z1 op cc;
    acomplex res=z-z1;
    z.getReal().set_gradient(1.0);
    s1.reverse();
    EXPECT_EQ(res.getReal().value(),0.0);
    EXPECT_EQ(res.getImm().value(),0.0);
    if (HasFailure())
    {
        std::cout<<"SComplex: "<<std::setprecision(Nprint)<<z<<std::endl;
        std::cout<<"AComplex: "<<std::setprecision(Nprint)<<z1<<std::endl;
    }
}

TEST(AComplexMixed, divideMixControl)
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
    dcomplex z1=dcomplex(a1,b1);
    s1.new_recording();
    acomplex z=acomplex(a,b);
    z  =z op cc;
    z1 =z1 op cc;
    acomplex res=z-z1;
    z.getReal().set_gradient(1.0);
    s1.reverse();
    EXPECT_EQ(res.getReal().value(),0.0);
    EXPECT_EQ(res.getImm().value(),0.0);
    if (HasFailure())
    {
        std::cout<<"SComplex: "<<std::setprecision(Nprint)<<z<<std::endl;
        std::cout<<"AComplex: "<<std::setprecision(Nprint)<<z1<<std::endl;
    }
}

////Functions

TEST(AComplexMixed, sinMixControl)
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
    double cc= (double)rand() / RAND_MAX;
    dcomplex z1=dcomplex(a1,b1);
    s1.new_recording();
    acomplex z=acomplex(a,b);
    z  =z*op(cc);
    z1 =z1*op(cc);
    acomplex res=z-z1;
    z.getReal().set_gradient(1.0);
    s1.reverse();
    EXPECT_EQ(res.getReal().value(),0.0);
    EXPECT_EQ(res.getImm().value(),0.0);
    if (HasFailure())
    {
        std::cout<<"SComplex: "<<std::setprecision(Nprint)<<z<<std::endl;
        std::cout<<"AComplex: "<<std::setprecision(Nprint)<<z1<<std::endl;
    }
}
TEST(AComplexMixed, cosMixControl)
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
//    double cc= (double)rand() / RAND_MAX;
    dcomplex z1=dcomplex(a1,b1);
    dcomplex zero=dcomplex(0.0,0.0);
    s1.new_recording();
    acomplex z=acomplex(a,b);
    z  =tan(z)*exp(z)*log(z1)*sin(z1);
//    z1 =z1 op cc;
    acomplex res=z*z1*zero;
    z.getReal().set_gradient(1.0);
    s1.reverse();
    EXPECT_EQ(res.getReal().value(),0.0);
    EXPECT_EQ(res.getImm().value(),0.0);
    if (HasFailure())
    {
        std::cout<<"SComplex: "<<std::setprecision(Nprint)<<z<<std::endl;
        std::cout<<"AComplex: "<<std::setprecision(Nprint)<<z1<<std::endl;
    }
}
