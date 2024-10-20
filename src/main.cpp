#include <iostream>
#include "../include/NetworkInfo.hpp"
int main()
{
    NetworkInfo networkInfo;
    networkInfo.ipInfo();
    std::cout << "Внутренний ip: " << networkInfo.getInrernalIP() << std::endl;
    return 0;
}