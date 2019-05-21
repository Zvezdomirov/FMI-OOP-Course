//
// Created by zvezdomirov98 on 17.05.19.
//

#ifndef P03_LOGIN_SYSTEM_GUEST_H
#define P03_LOGIN_SYSTEM_GUEST_H

class Guest {

public:
    Guest(const char *ip_address = DEFAULT_IP);

    Guest(const Guest &); //copy constructor

    Guest &operator=(const Guest &rhs);

    virtual ~Guest();

    char *getIpAddress() const;

    void setIpAddress(const char *ip_address);

protected:
    constexpr static const char* const DEFAULT_IP = "127.0.0.1";

private:
    char *m_ip_address;
};

#endif //P03_LOGIN_SYSTEM_GUEST_H
