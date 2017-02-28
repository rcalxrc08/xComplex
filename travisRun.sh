#!/bin/bash
mkdir CmakeInstaller
cd CmakeInstaller/
sudo apt-get install build-essential &> /dev/null
wget https://cmake.org/files/v3.7/cmake-3.7.2.tar.gz &> /dev/null
tar xf cmake-3.7.2.tar.gz &> /dev/null
cd cmake-3.7.2 &> /dev/null
./bootstrap &> /dev/null
make &> /dev/null
sudo make install &> /dev/null
sudo ldconfig &> /dev/null
cd ../
cd ../
mkdir Build/
cd Build/
cmake ..
make all
cd ../
cd bin/
./AComplexClass
./runAllTests
cd ../
