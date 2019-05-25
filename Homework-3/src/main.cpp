#include <iostream>
#include "Point2D.h"
#include "Player.h"
#include "Environment.h"
#include "Mob.h"

int main() {
//    Point2D p1(0,0);
//    Point2D p2(3,4);
//    std::cout << p2.getDistanceTo(p1) << std::endl;

    Player player1("Player1", *(new Point3D(1, 2, 3)), 20, 10);
    Environment* environment = &Environment::getInstance();
    environment->add(*new Mob("Mob1", *new Point3D(2, 3, 4), 10, 5));
    environment->add(*new Player("Player2", *new Point3D(-1, 2, 5), 15, 20));
    environment->add(*new Mob("Mob2", *new Point3D(10, 2, 18), 25, 30));

    for (int i = 0; environment->getAt(i) != nullptr; i++) {
        if (environment->getAt(i)->getType() == EntityType::MOB) {
            //TODO: Cast Entity to PlayableCharacter somehow
//            player1.attack(*environment->getAt(i));
        }
    }
    return 0;
}