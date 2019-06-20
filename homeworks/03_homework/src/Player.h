#include <utility>

//
// Created by zvezdomirov98 on 25.05.19.
//

#ifndef HOMEWORK_3_PLAYER_H
#define HOMEWORK_3_PLAYER_H


#include "Entity.h"
#include "PlayableCharacter.h"

class Player : public PlayableCharacter {
public:
    Player(std::string name,
           const Point3D &location,
           int damage,
           int health) :
            PlayableCharacter(std::move(name), location,
                              EntityType::PLAYER,
                              damage, health) {};
    bool attack(PlayableCharacter& target) override;
};


#endif //HOMEWORK_3_PLAYER_H
