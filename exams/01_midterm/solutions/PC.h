#ifndef PC_H
#define PC_H

#include "Monitor.h"

class PC
{
private:
    static const int DEFAULT_CAPACITY = 2;
    Monitor* monitorList;
    int monitorCount;
    int capacity;
    char* serialNumber;
    void resizeList();
    bool isFull() const;

public:
    PC();
    ~PC();
    int getMonitorCount() const;
    Monitor* getMonitorList() const;
    char* getSerialNumber() const;
    void setSerialNumber(char*);
    void addMonitor(const Monitor&);
    bool containsMonitor(char* serialNumber) const;
    PC& operator=(const PC&);
    Monitor& operator[](const int&);
};

#endif // PC_H
