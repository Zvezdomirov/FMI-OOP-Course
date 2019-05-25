//
// Created by zvezdomirov98 on 25.05.19.
//

#ifndef HOMEWORK_3_MOB_H
#define HOMEWORK_3_MOB_H


#include "PlayableCharacter.h"

class Mob : public PlayableCharacter {
public:
    Mob(std::string name,
        const Point3D &location,
        int damage,
        int health) :
            PlayableCharacter(
                    std::move(name),
                    location,
                    EntityType::MOB,
                    damage,
                    health) {};

    bool attack(PlayableCharacter &target) override;
};


#endif //HOMEWORK_3_MOB_H
