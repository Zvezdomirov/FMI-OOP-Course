#include <iostream>
#include <assert.h>
#include "Warrior.h"
#include "Guardian.h"
#include "Wizard.h"
#include <cstring>

int main() {

    Warrior warrior;
    Guardian guardian;
    Wizard wizard;
    Warrior copyWarrior = warrior;

    //Test the getAttacked() method
    assert(warrior.getHp() == 20);
    warrior.getAttacked(5);
    assert(warrior.getHp() == 16);

    //Test the getName() method
    assert(strcmp(guardian.getName(), "Guardian") == 0);

    //Test the copy constructor at compile time
    static_assert(&warrior != &copyWarrior,
            "Copy constructor copies just the address!");
    return 0;
}