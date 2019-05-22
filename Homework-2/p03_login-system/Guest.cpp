//
// Created by zvezdomirov98 on 20.05.19.
//
#include "Guest.h"
#include <cstring>

Guest::Guest(const char *ip_address) {
    m_ip_address = nullptr;
    setIpAddress(ip_address);
};

Guest::Guest(const Guest &copy) {
    m_ip_address = nullptr;
    setIpAddress(copy.m_ip_address);
}

Guest& Guest::operator=(const Guest &rhs) {
    delete[] m_ip_address;
    setIpAddress(rhs.m_ip_address);
}

Guest::~Guest() {
    delete[] m_ip_address;
}

char* Guest::getIpAddress() const {
    return m_ip_address;
}

void Guest::setIpAddress(const char *ip_address) {
    delete[] m_ip_address;
    int newLen = strlen(ip_address);
    m_ip_address = new char[newLen + 1];
    strcpy(m_ip_address, ip_address);
}
