//
// Created by zvezdomirov98 on 17.05.19.
//

#ifndef P02_MMORPG_GUARDIAN_H
#define P02_MMORPG_GUARDIAN_H

class Guardian : public GameCharacter {
public:
    Guardian() :
            GameCharacter("Guardian", 40, 25, 1, 3) {};
};

#endif //P02_MMORPG_GUARDIAN_H
