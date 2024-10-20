#pragma once

class NetworkInfo
{
    private:
        std::string internalIP;
        std::string externalIP;
    public:
        NetworkInfo();
        ~NetworkInfo();

        std::string ipInfo();
        std::string getInrernalIP()const;
        std::string getExternalIP()const;
};