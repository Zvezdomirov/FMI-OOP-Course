#include <iostream>
#include "GameCharacter.h"
#include "Warrior.h"
#include "Guardian.h"
#include "Wizzard.h"
#include <assert.h>

int main() {
    Warrior warrior;
    Guardian guardian;
    Wizzard wizzard;
    std::cout << warrior.getName() << std::endl;
    std::cout << guardian.getName() << std::endl;
    std::cout << wizzard.getName() << std::endl;

    assert(warrior.getHp() == 20);
    warrior.getAttacked(wizzard.getAp());
    assert(warrior.getHp() == 19); //20hp - (2ap - 1dp) = 19hp
    return 0;
}
