//
// Created by zvezdomirov98 on 17.05.19.
//

#ifndef P03_LOGIN_SYSTEM_POWERUSER_H
#define P03_LOGIN_SYSTEM_POWERUSER_H


#include "User.h"

class PowerUser : public virtual User {

public:
    PowerUser(const char *ip_address = DEFAULT_IP,
              const char *username = "",
              const char *password = "",
              const char *title = "",
              int reputation = 0) :
            User(ip_address, username, password, title),
            m_reputation(reputation) {};

    void gainReputation(const User &contributor);

    int getReputation() const;

private:
    int m_reputation;
};


#endif //P03_LOGIN_SYSTEM_POWERUSER_H
