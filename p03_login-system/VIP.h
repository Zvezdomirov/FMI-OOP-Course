//
// Created by zvezdomirov98 on 12.05.19.
//

#ifndef PO3_LOGIN_SYSTEM_VIP_H
#define PO3_LOGIN_SYSTEM_VIP_H

#include "User.h"

class VIP : public User {
public:
    VIP(char *ipAddress, char *username, char *password, char *title);

protected:
    void setTitle(char *title) override;

};

VIP::VIP(char *ipAddress, char *username,
        char *password, char *title) :
        User(ipAddress, username, password, title) {}

void VIP::setTitle(char *_title) {
    title = _title;
}

#endif //PO3_LOGIN_SYSTEM_VIP_H
