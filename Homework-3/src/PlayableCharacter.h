//
// Created by zvezdomirov98 on 25.05.19.
//

#ifndef HOMEWORK_3_PLAYABLECHARACTER_H
#define HOMEWORK_3_PLAYABLECHARACTER_H


#include "Entity.h"

class PlayableCharacter : public Entity {
protected:
    int m_damage;
    int m_health;

    PlayableCharacter(std::string name,
                      const Point3D &location,
                      EntityType type,
                      int damage,
                      int health) :
            Entity(std::move(name), location, type),
            m_damage(damage),
            m_health(health) {};

    virtual bool isAlive() const override;

    virtual bool attack(PlayableCharacter& target);
};


#endif //HOMEWORK_3_PLAYABLECHARACTER_H
