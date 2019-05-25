//
// Created by zvezdomirov98 on 25.05.19.
//

#include "Mob.h"

bool Mob::attack(PlayableCharacter &target) {
    if (target.getType() == EntityType::PLAYER) {
        return PlayableCharacter::attack(target);
    }
    return false;
}
