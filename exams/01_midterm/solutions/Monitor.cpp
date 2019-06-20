#include "Monitor.h"

Monitor::Monitor()
{
    height = 0;
    width = 0;
    serialNumber = "0000";
}

Monitor::Monitor(int height, int width, char* serialNumber)
{
    this->height = height;
    this->width = width;
    this->serialNumber = serialNumber;
}

Monitor::~Monitor()
{
}

int Monitor::getHeight() const
{
    return height;
}

void Monitor::setHeight(int height)
{
    this->height = height;
}

int Monitor::getWidth() const
{
    return width;
}

void Monitor::setWidth(int width)
{
    this->width = width;
}

char* Monitor::getSerialNumber() const
{
    return serialNumber;
}

void Monitor::setSerialNumber(char* serialNumber)
{
    this->serialNumber = serialNumber;
}

bool Monitor::operator<(const Monitor& mon) const
{
    if (width == mon.getWidth())
    {
        return height < mon.getHeight();
    }

    return width < mon.getWidth();
}

std::ostream& operator<<(std::ostream& os, const Monitor& mon)
{
    os << "Monitor height: " << mon.getHeight()
        << "\nMonitor width: " << mon.getWidth()
        << "\nMonitor serial number: " << mon.getSerialNumber() << "\n";
    return os;
}
