#ifndef MONITOR_H
#define MONITOR_H

#include <iostream>

class Monitor
{
private:
    int width;
    int height;
    char* serialNumber;

public:
    Monitor();
    Monitor(int, int, char*);
    ~Monitor();
    int getWidth() const;
    void setWidth(int width);
    int getHeight() const;
    void setHeight(int height);
    char* getSerialNumber() const;
    void setSerialNumber(char* serialNumber);
    bool operator<(const Monitor&) const;
    friend std::ostream& operator<<(std::ostream&, const Monitor&);
};

#endif
