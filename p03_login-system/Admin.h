//
// Created by zvezdomirov98 on 12.05.19.
//

#ifndef PO3_LOGIN_SYSTEM_ADMIN_H
#define PO3_LOGIN_SYSTEM_ADMIN_H

#include "PowerUser.h"
#include "User.h"

class Admin : public PowerUser {
public:
    Admin(char *ipAddress, char *username, char *password, char *title, int reputation);

    void setUserName(char *_username);

    void setExteriorUsername(User &user, char *newName);
};

Admin::Admin(char *ipAddress, char *username,
        char *password, char *title, int reputation) :
        PowerUser(ipAddress,
           username,
           password, title,
           reputation) {}

void Admin::setUserName(char* _username) {
    username = _username;
}

void Admin::setExteriorUsername(User& user, char* newName) {
    user.username = newName;
}
#endif //PO3_LOGIN_SYSTEM_ADMIN_H
