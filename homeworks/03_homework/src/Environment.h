//
// Created by zvezdomirov98 on 25.05.19.
//

#ifndef HOMEWORK_3_ENVIRONMENT_H
#define HOMEWORK_3_ENVIRONMENT_H


#include "Entity.h"
#include "Player.h"
#include <vector>
#include <memory>

class Environment {
public:
    static Environment &getInstance();

    void add(const std::shared_ptr<Entity>&);

    Entity *getAt(int index) const;

    void removeAt(int index);

    void generateEntities();

    void destroyEntities();

    Entity *getClosestAliveEntity(const Player &player,
                                  EntityType type) const;

    Environment(const Environment &) = delete;

    void operator=(const Environment &) = delete;

private:

    static Environment *instance;

    std::vector<std::shared_ptr<Entity>> m_entities;

    Environment() = default;

};


#endif //HOMEWORK_3_ENVIRONMENT_H
