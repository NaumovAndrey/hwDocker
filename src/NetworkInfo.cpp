#include <iostream>
#include <string>
#include <ifaddrs.h>
#include <arpa/inet.h>
#include <sstream>
#include <cstdlib>
#include "NetworkInfo.hpp"

NetworkInfo::NetworkInfo(){}
NetworkInfo::~NetworkInfo(){}

std::string NetworkInfo::getInrernalIP() const
{
    return internalIP;
}

std::string NetworkInfo::getExternalIP() const
{
    return std::string();
}

std::string NetworkInfo::ipInfo()
{
    struct ifaddrs* ifaddr; //список сетевых интерфейсов

    if (getifaddrs(&ifaddr) == -1) 
    {
        perror("getifaddrs");
        return "Ошибка при получении внутреннего ip-адреса";
    }

    for (struct ifaddrs* ifa = ifaddr; ifa != nullptr; ifa = ifa->ifa_next) {
        if (ifa->ifa_addr == nullptr) continue; // адрес интерфейса на уровне канала, если такой существует

        // Если это адрес IPv4 и имя интерфейса не "lo" (loopback)
        if (ifa->ifa_addr->sa_family == AF_INET && std::string(ifa->ifa_name) != "lo") {
            char ip[INET_ADDRSTRLEN];
            inet_ntop(AF_INET, &((struct sockaddr_in*)ifa->ifa_addr)->sin_addr, ip, sizeof(ip));
            internalIP = ip;
            break; 
        }
    }
    freeifaddrs(ifaddr);

    return internalIP;
}