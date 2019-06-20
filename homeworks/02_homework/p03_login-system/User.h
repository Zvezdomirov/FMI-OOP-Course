//
// Created by zvezdomirov98 on 17.05.19.
//

#ifndef P03_LOGIN_SYSTEM_USER_H
#define P03_LOGIN_SYSTEM_USER_H


#include "Guest.h"

class User : public Guest {

public:
    User(const char *ip_address = DEFAULT_IP,
         const char *username = "",
         const char *password = "",
         const char *title = "") :
            Guest(ip_address) {

        m_username = nullptr;
        m_password = nullptr;
        m_title = nullptr;
        setUsername(username);
        setPassword(password);
        setTitle(title);
    };

    User(const User &); //copy constructor

    User &operator=(const User &rhs);

    ~User() override;

    char *getUsername() const;

    char *getPassword() const;

    char *getTitle() const;

    void changePassword(const char *old_pass,
                        const char *new_pass);

    friend class Admin;

protected:

    char *m_username;
    char *m_password;
    char *m_title;

    void setTitle(const char *title);

    void setPassword(const char *password);

    char* encryptDecrypt(const char *toEncrypt) const;

    void setUsername(const char *username);
};


#endif //P03_LOGIN_SYSTEM_USER_H
