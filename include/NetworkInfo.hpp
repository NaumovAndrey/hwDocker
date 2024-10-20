#pragma once

class NetworkInfo
{
    private:
        std::string internalIP;
        std::string externalIP;
    public:
        NetworkInfo();
        ~NetworkInfo();
};