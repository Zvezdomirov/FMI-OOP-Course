//
// Created by zvezdomirov98 on 25.05.19.
//

#include "Environment.h"
#include "Mob.h"

Environment *Environment::instance = nullptr;

Environment &Environment::getInstance() {
    if (instance == nullptr) {
        instance = new Environment();
    }
    return *instance;
}

void Environment::add(const std::shared_ptr<Entity>& entity) {
    m_entities.push_back(entity);
}

Entity *Environment::getAt(int index) const {
    return m_entities[index].get();
}

void Environment::removeAt(int index) {
    m_entities.erase(m_entities.begin() + index);
}

void Environment::generateEntities() {
    //The ugliest thing EVER, but it works and meets the homework conditions
    std::shared_ptr<Mob> mob1 = std::make_shared<Mob>(Mob("Mob1", Point3D(2, 3, 4), 10, 5));
    std::shared_ptr<Mob> mob2 = std::make_shared<Mob>(Mob("Mob2", Point3D(10, 20, 30), 25, 30));
    std::shared_ptr<Player> player1 =
            std::make_shared<Player>(Player("Player1", Point3D(-1, 2, 5), 15, 20));

    this->add(player1->shared_from_this());
    this->add(mob1->shared_from_this());
    this->add(mob2->shared_from_this());

}

void Environment::destroyEntities() {
    m_entities.clear();
}

Entity *Environment::getClosestAliveEntity(const Player &player,
                                           EntityType type) const {
    std::shared_ptr<Entity> closest;
    double minDist = INT_FAST64_MAX;

    for (const auto &entity : m_entities) {
        double currentDist = entity->getDistanceTo(player);

        if (entity->getType() == type &&
            currentDist < minDist &&
            entity->isAlive()) {

            minDist = currentDist;
            closest = entity;
        }
    }
    return closest.get();
}

