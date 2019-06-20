//
// Created by zvezdomirov98 on 25.05.19.
//

#include "PlayableCharacter.h"

bool PlayableCharacter::isAlive() const {
    return m_health > 0;
}

bool PlayableCharacter::attack(PlayableCharacter &target) {
    if (getDistanceTo(target) < 5) {
        target.m_health -= m_damage;
        return true;
    }
    return false;
}
