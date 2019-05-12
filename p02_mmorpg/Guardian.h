//
// Created by zvezdomirov98 on 12.05.19.
//

#ifndef P02_MMORPG_GUARDIAN_H
#define P02_MMORPG_GUARDIAN_H

#include "GameCharacter.h"

class Guardian : public GameCharacter {
public:
    Guardian() :
    GameCharacter("Guardian", 40, 25, 1, 3) {}
};

#endif //P02_MMORPG_GUARDIAN_H
