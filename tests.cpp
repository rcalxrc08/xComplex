#include "gtest/gtest.h"
#include "gtests/googlemock/include/gmock/gmock.h"
#include "xcomplex/Include/adatan2.h"

int main(int argc, char **argv)
{
    std::cout<<NAMELIB<<std::endl;
    testing::InitGoogleTest(&argc, argv);
    std::cout<<"Starting Test"<<std::endl;
    int Out= RUN_ALL_TESTS();
#ifdef _WIN32
	system("pause");
#endif
	return Out;
}
