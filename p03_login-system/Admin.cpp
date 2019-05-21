//
// Created by zvezdomirov98 on 17.05.19.
//

#include <cstring>
#include "Admin.h"

void Admin::setUsername(const char *username, User &user) {
    delete[] user.m_username;
    size_t l = strlen(username);
    user.m_username = new char[l + 1];
    strcpy(user.m_username, username);
}

void Admin::setUsername(const char *username) {
    User::setUsername(username);
}
