#include "../xcomplex/Include/acomplex.h"
#include "gtest/gtest.h"
#include <complex>
#define op operazione
#define Nprint 20
#define toll1 1E-9

TEST(AComplexDerivative, log)
{
#undef op
#define op(N1) log(N1)
    Real aa= (Real)rand() / RAND_MAX;
    Real bb= (Real)rand() / RAND_MAX;
    adept::Stack s1;
    AReal a=aa;
    AReal b=bb;
    Real a1=aa;
    Real b1=bb;
    s1.new_recording();
    acomplex z=acomplex(a,b);
    std::complex<Real> z1=std::complex<Real>(a1,b1);
    Real dx=toll1;
    auto Dx=std::complex<Real>(dx,0.0);
    Real yDy=op (z1+Dx).real();
    Real y=op (z1).real();
    Real FDDer=(yDy-y)/dx;
    z  =op (z);
    z.getReal().set_gradient(1.0);
    s1.reverse();
    Real ADDer=a.get_gradient();
    Real DerToll=toll1*1000;
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
#define op(N1) sin(N1)
    Real aa= (Real)rand() / RAND_MAX;
    Real bb= (Real)rand() / RAND_MAX;
    adept::Stack s1;
    AReal a=aa;
    AReal b=bb;
    Real a1=aa;
    Real b1=bb;
    s1.new_recording();
    acomplex z=acomplex(a,b);
    std::complex<Real> z1=std::complex<Real>(a1,b1);
    Real dx=toll1;
    auto Dx=std::complex<Real>(dx,0.0);
    Real yDy=op (z1+Dx).real();
    Real y=op (z1).real();
    Real FDDer=(yDy-y)/dx;

    z  =op (z);
    z.getReal().set_gradient(1.0);
    s1.reverse();
    Real ADDer=a.get_gradient();
    Real DerToll=toll1*1000;
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
#define op(N1) cos(N1)
    Real aa= (Real)rand() / RAND_MAX;
    Real bb= (Real)rand() / RAND_MAX;
    adept::Stack s1;
    AReal a=aa;
    AReal b=bb;
    Real a1=aa;
    Real b1=bb;
    s1.new_recording();
    acomplex z=acomplex(a,b);
    std::complex<Real> z1=std::complex<Real>(a1,b1);
    Real dx=toll1;
    auto Dx=std::complex<Real>(dx,0.0);
    Real yDy=op (z1+Dx).real();
    Real y=op (z1).real();
    Real FDDer=(yDy-y)/dx;

    z  =op (z);
    z.getReal().set_gradient(1.0);
    s1.reverse();
    Real ADDer=a.get_gradient();
    Real DerToll=toll1*1000;
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
#define op(N1) tan(N1)
    Real aa= (Real)rand() / RAND_MAX;
    Real bb= (Real)rand() / RAND_MAX;
    adept::Stack s1;
    AReal a=aa;
    AReal b=bb;
    Real a1=aa;
    Real b1=bb;
    s1.new_recording();
    acomplex z=acomplex(a,b);
    std::complex<Real> z1=std::complex<Real>(a1,b1);
    Real dx=toll1;
    auto Dx=std::complex<Real>(dx,0.0);
    Real yDy=op (z1+Dx).real();
    Real y=op (z1).real();
    Real FDDer=(yDy-y)/dx;

    z  =op (z);
    z.getReal().set_gradient(1.0);
    s1.reverse();
    Real ADDer=a.get_gradient();
    Real DerToll=toll1*1000;
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
#define op(N1) exp(N1)
    Real aa= (Real)rand() / RAND_MAX;
    Real bb= (Real)rand() / RAND_MAX;
    adept::Stack s1;
    AReal a=aa;
    AReal b=bb;
    Real a1=aa;
    Real b1=bb;
    s1.new_recording();
    acomplex z=acomplex(a,b);
    std::complex<Real> z1=std::complex<Real>(a1,b1);
    Real dx=toll1;
    auto Dx=std::complex<Real>(dx,0.0);
    Real yDy=op (z1+Dx).real();
    Real y=op (z1).real();
    Real FDDer=(yDy-y)/dx;

    z  =op (z);
    z.getReal().set_gradient(1.0);
    s1.reverse();
    Real ADDer=a.get_gradient();
    Real DerToll=toll1*1000;
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
#define op(N1) exp(sin(log(cos(N1))))
    Real aa= (Real)rand() / RAND_MAX;
    Real bb= (Real)rand() / RAND_MAX;
    adept::Stack s1;
    AReal a=aa;
    AReal b=bb;
    Real a1=aa;
    Real b1=bb;
    s1.new_recording();
    acomplex z=acomplex(a,b);
    std::complex<Real> z1=std::complex<Real>(a1,b1);
    Real dx=toll1;
    auto Dx=std::complex<Real>(dx,0.0);
    Real yDy=op (z1+Dx).real();
    Real y=op (z1).real();
    Real FDDer=(yDy-y)/dx;

    z  =op(z);
    z.getReal().set_gradient(1.0);
    s1.reverse();
    Real ADDer=a.get_gradient();
    Real DerToll=toll1*1000;
    /*std::cout<<"SComplex: "<<std::setprecision(Nprint)<<FDDer<<std::endl;
    std::cout<<"AComplex: "<<std::setprecision(Nprint)<<a.get_gradient()<<std::endl;*/
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
#define op(N1) exp(sin(sin(sin(N1))))
    Real aa= (Real)rand() / RAND_MAX;
    Real bb= (Real)rand() / RAND_MAX;
    adept::Stack s1;
    AReal a=aa;
    AReal b=bb;
    Real a1=aa;
    Real b1=bb;
    s1.new_recording();
    acomplex z=acomplex(a,b);
    std::complex<Real> z1=std::complex<Real>(a1,b1);
    Real dx=toll1;
    auto Dx=std::complex<Real>(dx,0.0);
    Real yDy=op (z1+Dx).real();
    Real y=op (z1).real();
    Real FDDer=(yDy-y)/dx;
    z  =op (z);
    z.getReal().set_gradient(1.0);
    s1.reverse();
    Real ADDer=a.get_gradient();
    Real DerToll=toll1*1000;
    /*std::cout<<"SComplex: "<<std::setprecision(Nprint)<<FDDer<<std::endl;
    std::cout<<"AComplex: "<<std::setprecision(Nprint)<<a.get_gradient()<<std::endl;*/
    EXPECT_NEAR(FDDer, ADDer,DerToll);
    if (HasFailure())
    {
        std::cout<<"SComplex: "<<std::setprecision(Nprint)<<FDDer<<std::endl;
        std::cout<<"AComplex: "<<std::setprecision(Nprint)<<a.get_gradient()<<std::endl;
    }
}

TEST(AComplexDerivative, mixed3)
{
#undef op
#define op(N1) cos(tan(exp(sin(cos(log(N1))))))
    Real aa= (Real)rand() / RAND_MAX;
    Real bb= (Real)rand() / RAND_MAX;
    adept::Stack s1;
    AReal a=aa;
    AReal b=bb;
    Real a1=aa;
    Real b1=bb;
    s1.new_recording();
    acomplex z=acomplex(a,b);
    std::complex<Real> z1=std::complex<Real>(a1,b1);
    Real dx=toll1;
    auto Dx=std::complex<Real>(dx,0.0);
    Real yDy=op (z1+Dx).real();
    Real y=op (z1).real();
    Real FDDer=(yDy-y)/dx;

    z  =op (z);
    z.getReal().set_gradient(1.0);
    s1.reverse();
    Real ADDer=a.get_gradient();
    Real DerToll=toll1*1000;
    /*std::cout<<"SComplex: "<<std::setprecision(Nprint)<<FDDer<<std::endl;
    std::cout<<"AComplex: "<<std::setprecision(Nprint)<<a.get_gradient()<<std::endl;*/
    EXPECT_NEAR(FDDer, ADDer,DerToll);
    if (HasFailure())
    {
        std::cout<<"SComplex: "<<std::setprecision(Nprint)<<FDDer<<std::endl;
        std::cout<<"AComplex: "<<std::setprecision(Nprint)<<a.get_gradient()<<std::endl;
    }
}

TEST(AComplexDerivative, mixed4)
{
#undef op
//#define op(N1) (cos(tan(exp(sin(cos(log(N1))))))+N1*cos(N1))
#define op(N1) exp(N1)
    Real aa= (Real)rand() / RAND_MAX;
    Real bb= (Real)rand() / RAND_MAX;
    adept::Stack s1;
    AReal a=aa;
    AReal b=bb;
    Real a1=aa;
    Real b1=bb;
    s1.new_recording();
    acomplex z=acomplex(a,b);
    std::complex<Real> z1=std::complex<Real>(a1,b1);
    Real dx=toll1;
    auto Dx=std::complex<Real>(dx,0.0);
    Real yDy=op (z1+Dx).real();
    Real y=op (z1).real();
    Real FDDer=(yDy-y)/dx;

    z  =op (z);
    z.getReal().set_gradient(1.0);
    s1.reverse();
    Real ADDer=a.get_gradient();
    Real DerToll=toll1*1000;
    /*std::cout<<"SComplex: "<<std::setprecision(Nprint)<<FDDer<<std::endl;
    std::cout<<"AComplex: "<<std::setprecision(Nprint)<<a.get_gradient()<<std::endl;*/
    EXPECT_NEAR(FDDer, ADDer,DerToll);
    if (HasFailure())
    {
        std::cout<<"SComplex: "<<std::setprecision(Nprint)<<FDDer<<std::endl;
        std::cout<<"AComplex: "<<std::setprecision(Nprint)<<a.get_gradient()<<std::endl;
    }
}