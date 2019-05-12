//
// Created by zvezdomirov98 on 12.05.19.
//

#ifndef P02_MMORPG_WARRIOR_H
#define P02_MMORPG_WARRIOR_H

#include "GameCharacter.h"

class Warrior : public GameCharacter {
public:
    Warrior() :
    GameCharacter("Warrior", 20, 5, 4, 1) {}
};

#endif //P02_MMORPG_WARRIOR_H
