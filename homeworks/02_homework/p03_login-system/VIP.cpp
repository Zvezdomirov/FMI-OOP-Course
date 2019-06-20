//
// Created by zvezdomirov98 on 17.05.19.
//

#include <cstring>
#include "VIP.h"
#include "User.h"


void VIP::changeTitle(const char *title){
    //Bad practice. Research how to use setTitle as public in VIP
    setTitle(title);
}