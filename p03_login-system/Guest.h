//
// Created by zvezdomirov98 on 12.05.19.
//

#ifndef PO3_LOGIN_SYSTEM_GUEST_H
#define PO3_LOGIN_SYSTEM_GUEST_H

class Guest {
public:
    Guest(char *ipAddress);

    char *getIpAddress() const;

    void setIpAddress(char *ipAddress);

private:
    char* ipAddress;
};

Guest::Guest(char *ipAddress) : ipAddress(ipAddress) {}

char *Guest::getIpAddress() const {
    return ipAddress;
}

void Guest::setIpAddress(char *ipAddress) {
    Guest::ipAddress = ipAddress;
}

#endif //PO3_LOGIN_SYSTEM_GUEST_H
