#include <iostream>
#include "Point2D.h"
#include "Player.h"
#include "Environment.h"
#include "Mob.h"

int main() {
    Environment *environment = &Environment::getInstance();

    environment->generateEntities();
    auto player1 = dynamic_cast<Player *>(environment->getAt(0));

    Mob *toAttack;
    /*While there is an alive entity of type Mob nearby,
     * cast it to Mob* and pass it as attack
     * parameter to player1. If attacking is
     * unsuccessful, it means that even the closest
     * Mob is too far away, so we break the loop.
     * */
    while ((toAttack = dynamic_cast<Mob *>(
            environment->getClosestAliveEntity(
                    *player1, EntityType::MOB))) &&
                    toAttack->isAlive()) {

        if (!player1->attack(*toAttack)) {
            break;
        }
    }
    return 0;
}