#include <iostream>
#include <assert.h>
//#include "MagicBox.h"
#include "MyArray.h"
#include "MagicBox.h"

int main() {
    MagicBox<int> box;
    box.insert(5);
    box.insert(6);
    box.insert(7);
    box.insert(8);
    box.insert(9);
    box.insert(10);
    box.pop();
    box.pop();
    box.list();
    return 0;
}