#include <cassert>
#include "acomplex.h"
#include "gtest/gtest.h"
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
    z.getReal().set_gradient(1.0);
    s1.reverse();
    EXPECT_EQ(z1.real(), z.getReal().value());
    EXPECT_EQ(z1.imag(), z.getImm().value());
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
    z.getReal().set_gradient(1.0);
    s1.reverse();
    EXPECT_EQ(z1.real(), z.getReal().value());
    EXPECT_EQ(z1.imag(), z.getImm().value());
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
    z.getReal().set_gradient(1.0);
    s1.reverse();
    EXPECT_EQ(z1.real(), z.getReal().value());
    EXPECT_EQ(z1.imag(), z.getImm().value());
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
    z.getReal().set_gradient(1.0);
    s1.reverse();
    /*EXPECT_EQ(z1.real(), z.getReal().value());
    EXPECT_EQ(z1.imag(), z.getImm().value());*/
    double toll=1e-14;
    EXPECT_NEAR(z1.real(), z.getReal().value(),toll);
    EXPECT_NEAR(z1.imag(), z.getImm().value(),toll);
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
    z.getReal().set_gradient(1.0);
    s1.reverse();
    EXPECT_EQ(z1.real(), z.getReal().value());
    EXPECT_EQ(z1.imag(), z.getImm().value());
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
    z.getReal().set_gradient(1.0);
    s1.reverse();
    EXPECT_EQ(z1.real(), z.getReal().value());
    EXPECT_EQ(z1.imag(), z.getImm().value());
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
    z.getReal().set_gradient(1.0);
    s1.reverse();
    EXPECT_EQ(z1.real(), z.getReal().value());
    EXPECT_EQ(z1.imag(), z.getImm().value());
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
    z.getReal().set_gradient(1.0);
    s1.reverse();
    EXPECT_EQ(z1.real(), z.getReal().value());
    EXPECT_EQ(z1.imag(), z.getImm().value());
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
    z.getReal().set_gradient(1.0);
    s1.reverse();
    EXPECT_EQ(z1.real(), z.getReal().value());
    EXPECT_EQ(z1.imag(), z.getImm().value());
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
    z.getReal().set_gradient(1.0);
    s1.reverse();
    auto toll=1e-14;
    EXPECT_NEAR(z1.real(), z.getReal().value(),toll);
    EXPECT_NEAR(z1.imag(), z.getImm().value(),toll);
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
    z.getReal().set_gradient(1.0);
    s1.reverse();
    EXPECT_EQ(z1.real(), z.getReal().value());
    EXPECT_EQ(z1.imag(), z.getImm().value());
    if (HasFailure())
    {
        std::cout<<"SComplex: "<<std::setprecision(Nprint)<<z<<std::endl;
        std::cout<<"AComplex: "<<std::setprecision(Nprint)<<z1<<std::endl;
    }
}

TEST(AComplex, MixedTest)
{
#undef op
#define op(x) exp(cos(x))*x+x*sin(x)
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
    z.getReal().set_gradient(1.0);
    s1.reverse();
    EXPECT_EQ(z1.real(), z.getReal().value());
    EXPECT_EQ(z1.imag(), z.getImm().value());
    if (HasFailure())
    {
        std::cout<<"SComplex: "<<std::setprecision(Nprint)<<z<<std::endl;
        std::cout<<"AComplex: "<<std::setprecision(Nprint)<<z1<<std::endl;
    }
}

TEST(AComplex, MixedTest2)
{
#undef op
#define op(x) exp(cos(x))*x+x*sin(x)
    Real aa= (Real)rand() / RAND_MAX;
    Real bb= (Real)rand() / RAND_MAX;
    adept::Stack s1;
    adept::adouble a2=aa;
    adept::adouble b2=bb;
    Real a1=aa;
    Real b1=bb;
    s1.new_recording();


    //USELESS, check if it compiles
    adept::adouble a=1.0;
    adept::adouble b=1.0;
    acomplex X=acomplex(a,b);
    dcomplex c=dcomplex(1.0,0.0);
    c+=4;
    c=c+6;
    auto d=c*b;
    d=d-X;
    d=X-d;
    acomplex X1=c/X+X*X+X+exp(c)*c*a*acomplex(1.0,0.0)*exp(c)+sin(X)+exp(X)*exp(c)*tan(c)+c+exp(c)+exp(X)/c;
    X1-=2.;
    X1-=a;
    //Mixed Complex
    X1*=c;
    X1/=c;
    X1+=c;
    X1-=c;
    X1=X1+c;
    X1=c+X1;
    X1=c*X1;
    X1=X1*c;
    X1=X1/c;
    X1=c/X1;
    X1=c-X1;
    X1=X1-c;
    X1+=c;
    X1*=c;
    X1/=c;
    X1-=c;
    //Mixed ADouble
    X1=a+X1;
    X1=X1+a;
    X1=X1-a;
    X1=a-X1;
    X1=a/X1;
    X1=X1/a;
    X1=a+X1;
    X1=X1+a;
    X1=X1*a;
    X1=a*X1;


//Mixed Double
    X1=X1/2.;
    X1=2./X1;
    X1=2.+X1;
    X1=X1+2.;
    X1=2.*X1;//Da Modificare
    X1=X1*2.;
    X1=2-X1;
    X1=X1-2.;

    X1*=X1;
    X1/=X1;
    X1-=X1;
    X1+=X1;
    //
    //// FAILS
    /*X1-=2.;
    X1+=2.;
    X1/=2.;
    X1*=2.;*/
    ////FAILS
/*    X1*=b;
    X1/=b;
    X1+=b;
    X1-=b;*/
    //
    X1*=c;
    X1/=c;
    X1-=c;
    X1+=c;
    acomplex tmp;
    tmp+=c*a;
    tmp+=a*c;
    tmp+=c/a;
    tmp+=a/c;
    tmp+=c+a;
    tmp+=a+c;
    tmp+=c-a;
    tmp+=a-c;
    tmp*=c;
    tmp/=c;
    tmp+=c;
    tmp-=c;
//END USELESS


    acomplex z=acomplex(a2,b2);
    std::complex<double> z1=std::complex<double>(a1,b1);
    z  = op (z);
    z1 = op (z1);
	z.getReal().set_gradient(1.0);
    s1.reverse();
    EXPECT_NEAR(z1.real(), z.getReal().value(),toll1);
    EXPECT_NEAR(z1.imag(), z.getImm().value(),toll1);
    if (HasFailure())
    {
        std::cout<<"SComplex: "<<std::setprecision(Nprint)<<z<<std::endl;
        std::cout<<"AComplex: "<<std::setprecision(Nprint)<<z1<<std::endl;
    }
}
