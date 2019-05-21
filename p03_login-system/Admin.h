//
// Created by zvezdomirov98 on 17.05.19.
//

#ifndef P03_LOGIN_SYSTEM_ADMIN_H
#define P03_LOGIN_SYSTEM_ADMIN_H


#include "User.h"
#include "PowerUser.h"
#include "VIP.h"

class Admin :
        public VIP,
        public PowerUser {
public:
    Admin(const char *ip_address = DEFAULT_IP,
          const char *username = "",
          const char *password = "",
          const char *title = "",
          int reputation = 0) :
            PowerUser(ip_address,
                      username,
                      password,
                      title,
                      reputation) {};

    void setUsername(const char *username,
                     User &user);
    void setUsername(const char *username);
};


#endif //P03_LOGIN_SYSTEM_ADMIN_H
