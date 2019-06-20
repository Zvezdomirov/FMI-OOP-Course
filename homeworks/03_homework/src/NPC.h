//
// Created by zvezdomirov98 on 25.05.19.
//

#ifndef HOMEWORK_3_NPC_H
#define HOMEWORK_3_NPC_H


#include "Entity.h"

class NPC : public Entity {
public:
    NPC(std::string name,
        const Point3D &location) :
            Entity(std::move(name),
                   location,
                   EntityType::NPC) {};
};


#endif //HOMEWORK_3_NPC_H
