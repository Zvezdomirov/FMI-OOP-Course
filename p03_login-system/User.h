//
// Created by zvezdomirov98 on 12.05.19.
//

#ifndef PO3_LOGIN_SYSTEM_USER_H
#define PO3_LOGIN_SYSTEM_USER_H

#include <iostream>
#include "Guest.h"

class User : public Guest {
public:
    User(char *ipAddress, char *username, char *password, char *title);

    char *getUsername() const;

    char *getPassword() const;

    char *getTitle() const;

protected:

    void changePassword(char *oldPass, char *newPass);

    char * encryptDecrypt(char *toEncrypt) const;

    bool strEquals(char *str1, char *str2);

    virtual void setTitle(char* title);

    char* username;
    char* password;
    char* title;

    friend class Admin;
};

User::User(char *ipAddress, char *username,
        char *password, char *title) :
        Guest(ipAddress), username(username), title(title) {
    this->password = encryptDecrypt(password);
}

char *User::getUsername() const {
    return username;
}

char *User::getPassword() const {
    return encryptDecrypt(password);
}

void User::changePassword(char* oldPass, char* newPass) {
    if (strEquals(oldPass, encryptDecrypt(password))) {
        password = encryptDecrypt(newPass);
    } else {
        std::cerr << "Incorrect old password!\n";
    }
}

bool User::strEquals(char* str1, char* str2) {
    while (*str1++ && *str2++) {
        if (*str1 != *str2) {
            return false;
        }
    }
    return true;
}

//simple XOR encryption
char * User::encryptDecrypt(char* toEncrypt) const {
    const char key = '_';
    while (*toEncrypt != '\0') {
        *toEncrypt++ ^= key;
        toEncrypt++;
    }
    return toEncrypt;
}

char *User::getTitle() const {
    return title;
}

void User::setTitle(char *title) {
    std::cerr << "Regular users can't change their title!\n";
}

#endif //PO3_LOGIN_SYSTEM_USER_H
