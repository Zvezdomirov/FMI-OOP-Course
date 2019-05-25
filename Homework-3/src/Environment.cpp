//
// Created by zvezdomirov98 on 25.05.19.
//

#include "Environment.h"

Environment *Environment::instance = nullptr;

Environment &Environment::getInstance() {
    if (instance == nullptr) {
        instance = new Environment();
    }
    return *instance;
}

void Environment::add(const Entity &entity) {
    m_entities.push_back(std::make_shared<Entity>(entity));
}

Entity *Environment::getAt(int index) const {
    return m_entities[index].get();
}

void Environment::removeAt(int index) {
    m_entities.erase(m_entities.begin() + index);
}

//TODO: Generate random number of different entities and add them
void Environment::generateEntities() {

}

void Environment::destroyEntities() {
    m_entities.clear();
}

Entity *Environment::getClosestAliveEntity(const Player &player,
                                           EntityType &type) const {
    std::shared_ptr<Entity> closest;
    double minDist = INT_FAST64_MAX;

    for (const auto &entity : m_entities) {
        double currentDist = entity->getDistanceTo(player);

        if (entity->getType() == PLAYER &&
            currentDist < minDist &&
            entity->isAlive()) {

            minDist = currentDist;
            closest = entity;
        }
    }
    return closest.get();
}

