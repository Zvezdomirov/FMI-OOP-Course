#include <iostream>
#include "Point2D.h"
#include "Player.h"
#include "Environment.h"
#include "Mob.h"

int main() {
    Player player1("Player1", Point3D(1, 2, 3), 20, 10);
    Environment *environment = &Environment::getInstance();
    environment->add(Mob("Mob1", Point3D(2, 3, 4), 10, 5));
    environment->add(Player("Player2", Point3D(-1, 2, 5), 15, 20));
    environment->add(Mob("Mob2", Point3D(10, 2, 18), 25, 30));

    Mob *toAttack;
    /*While there is an entity of type mob nearby,
     * cast it to Mob* and pass it as attack
     * parameter to player1*/
    while ((toAttack = dynamic_cast<Mob *>(
            environment->getClosestAliveEntity(
                    player1, EntityType::MOB)))) {
        player1.attack(*toAttack);
    }
    return 0;
}