#include <iostream>
#include <assert.h>
#include "MagicBox.h"

int main() {
    MagicBox<int> box(5);
    box.insert(5);
    box.insert(6);
    box.insert(7);
    box.insert(8);
    box.insert(9);
    box.insert(10);
    box.list(std::cout);
    assert(box.getCapacity() == 10);
    assert(box.getSize() == 6);
    box.pop();
    assert(box.getSize() == 5);
    assert(!box.empty());
    return 0;
}