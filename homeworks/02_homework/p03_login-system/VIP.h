//
// Created by zvezdomirov98 on 17.05.19.
//

#ifndef P03_LOGIN_SYSTEM_VIP_H
#define P03_LOGIN_SYSTEM_VIP_H


#include "User.h"

class VIP : public virtual User {

public:
    VIP(const char *ip_address = "127.0.0.1",
        const char *username = "",
        const char *password = "",
        const char *title = "") :
            User(ip_address, username, password, title) {};

    void changeTitle(const char *title);
};


#endif //P03_LOGIN_SYSTEM_VIP_H
