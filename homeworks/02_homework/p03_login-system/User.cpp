//
// Created by zvezdomirov98 on 17.05.19.
//

#include <cstring>
#include <stdexcept>
#include "User.h"

User::User(const User &copy) :
        Guest(copy) {
    setUsername(copy.m_username);
    setPassword(copy.m_password);
    setTitle(copy.m_title);
}

User &User::operator=(const User &rhs) {
    if (this != &rhs) {
        //TODO: Read how to use the Guest's operator=
        setIpAddress(rhs.getIpAddress());
        setUsername(rhs.m_username);
        setPassword(rhs.m_password);
        setTitle(rhs.m_title);
    }
    return *this;
}

User::~User() {
    delete[] m_username;
    delete[] m_password;
    delete[] m_title;
}


void User::setUsername(const char *username) {
    delete[] m_username;
    int len = strlen(username);
    m_username = new char[len + 1];
    strcpy(m_username, username);
}

char *User::getUsername() const {
    return m_username;
}

char *User::getPassword() const {
    return m_password;
}

void User::setPassword(const char *password) {
    delete[] m_password;
    int len = strlen(password);
    m_password = new char[len + 1];
    strcpy(m_password, encryptDecrypt(password));
}

char* User::encryptDecrypt(const char *toEncrypt) const {
    char key = 'K';
    int len = strlen(toEncrypt);
    char *encrypted = new char[len + 1];
    for (int i = 0; i < len; i++) {
        encrypted[i] = toEncrypt[i] ^ key;
    }
    encrypted[len] = 0;

    return encrypted;
}

char *User::getTitle() const {
    return m_title;
}

void User::setTitle(const char *title) {
    delete[] m_title;
    int len = strlen(title);
    m_title = new char[len + 1];
    strcpy(m_title, title);
}

void User::changePassword(const char *old_pass,
        const char *new_pass) {
    if (strcmp(encryptDecrypt(m_password), old_pass) == 0) {
        setPassword(new_pass);
    } else {
        throw std::invalid_argument("Old password doesn't match!");
    }
}