#include <iostream>
#include "xcomplex/Include/adatan2.h"

#ifdef USE_ADDICT
#include "ad/ad.h"
DECLARE_ADGRAPH();
#endif
int main()
{

    std::cout << "Hello Complex Tester!" << std::endl<< std::endl;
    std::cout<<NAMELIB<<std::endl;

    return 0;
}