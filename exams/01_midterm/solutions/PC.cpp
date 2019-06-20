#include "PC.h"

PC::PC()
{
    capacity = DEFAULT_CAPACITY;
    monitorList = new Monitor[capacity];
    monitorCount = 0;
    serialNumber = "0000";
}

PC::~PC()
{
    delete[] monitorList;
}

int PC::getMonitorCount() const
{
    return monitorCount;
}

Monitor* PC::getMonitorList() const
{
    return monitorList;
}

char* PC::getSerialNumber() const
{
    return serialNumber;
}

void PC::setSerialNumber(char* serialNumber)
{
    this->serialNumber = serialNumber;
}

void PC::addMonitor(const Monitor& mon)
{
    if (isFull())
    {
        resizeList();
    }
    monitorList[monitorCount++] = mon;
}

void PC::resizeList()
{
    int newCapacity = capacity * 2;
    Monitor* newList = new Monitor[newCapacity];

    for (int i = 0; i < capacity; i++)
    {
        newList[i] = monitorList[i];
    }
    delete[] monitorList;
    capacity = newCapacity;
    monitorList = newList;
}

bool PC::isFull() const
{
    return monitorCount == capacity;
}

bool PC::containsMonitor(char* serialNumber) const
{
    for (int i = 0; i < monitorCount; i++)
    {
        if (monitorList[i].getSerialNumber() == serialNumber)
        {
            return true;
        }
    }
    return false;
}

