//
// Created by zvezdomirov98 on 17.05.19.
//

#include <cstring>
#include <stdexcept>
#include "PowerUser.h"

void PowerUser::gainReputation(const User &contributor) {
    if (strcmp(contributor.getUsername(), m_username) != 0) {
        m_reputation++;
    } else {
        throw std::invalid_argument("Power users can't give reputation to themselves!");
    }
}

int PowerUser::getReputation() const {
    return m_reputation;
}
