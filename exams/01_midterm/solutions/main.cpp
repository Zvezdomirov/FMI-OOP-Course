#include "Monitor.h"
#include <iostream>

int main()
{
    Monitor m(1080, 1080, "000110");
    Monitor m2 = m;
    m2.setHeight(720);
    m.setSerialNumber("11111");
    std::cout << m.getSerialNumber() << std::endl;
    std::cout << m.getWidth() << std::endl;
    std::cout << (m2 < m) << std::endl;
    std::cout << m;
}
