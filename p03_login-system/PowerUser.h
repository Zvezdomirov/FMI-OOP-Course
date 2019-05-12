//
// Created by zvezdomirov98 on 12.05.19.
//

#ifndef PO3_LOGIN_SYSTEM_POWERUSER_H
#define PO3_LOGIN_SYSTEM_POWERUSER_H

#include "User.h"

class PowerUser : public User {
public:
    PowerUser(char *ipAddress, char *username, char *password, char *title, int reputation);

    int getReputation() const;

private:
    int reputation;

    void increaseReputation(const User &contributor);

protected:
    void setTitle(char *title) override;
};

PowerUser::PowerUser(char *ipAddress, char *username,
                     char *password, char *title, int reputation) :
        User(ipAddress,
             username,
             password,
             title),
             reputation(0){}

void PowerUser::setTitle(char *_title) {
    title = _title;
}

int PowerUser::getReputation() const {
    return reputation;
}

void PowerUser::increaseReputation(const User &contributor) {
    if (!strEquals(this->getUsername(), contributor.getUsername())) {
        reputation++;
    } else {
        std::cerr << "Self-contributing is not allowed!\n";
    }
}

#endif //PO3_LOGIN_SYSTEM_POWERUSER_H
