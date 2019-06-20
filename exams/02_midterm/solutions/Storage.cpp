#include "Storage.h"

#include <iostream>
#include <cstring>

Storage::Storage(const char *hashcode,
	const char *name,
	int max_capacity,
	int used_capacity) :
		m_max_capacity(max_capacity),
		m_used_capacity(used_capacity) {

	setHashcode(hashcode);
	setName(name);
}

Storage::Storage(const Storage &copy)
{
	setName(copy.m_name);
	setHashcode(copy.m_hashcode);
	m_max_capacity = copy.m_max_capacity;
	m_used_capacity = copy.m_used_capacity;
}

Storage & Storage::operator=(const Storage & rhs)
{
	if (this != &rhs) {
		delete[] m_hashcode;
		delete[] m_name;
		setHashcode(rhs.m_hashcode);
		setName(rhs.m_name);
		m_max_capacity = rhs.m_max_capacity;
		m_used_capacity = rhs.m_used_capacity;
	}

	return *this;
}

Storage::~Storage() {
	delete[] m_hashcode;
	delete[] m_name;
}

char *Storage::getHashcode() const {
	return m_hashcode;
}

void Storage::setHashcode(const char *hashcode) {
	//delete[] hashcode;
	m_hashcode = new char[strlen(hashcode) + 1];
	strcpy(m_hashcode, hashcode);
}

char *Storage::getName() const {
	return m_name;
}

void Storage::setName(const char *name) {
	//delete[] name
	m_name = new char[strlen(name) + 1];
	strcpy(m_name, name);
}

int Storage::getMaxCapacity() const {
	return m_max_capacity;
}

void Storage::setMaxCapacity(int max_capacity) {
	m_max_capacity = max_capacity;
}

int Storage::getUsedCapacity() const {
	return m_used_capacity;
}

void Storage::setUsedCapacity(int used_capacity) {
	if (used_capacity > m_max_capacity) {
		std::cerr << "Max capacity reached!\n";
		return;
	}
	m_used_capacity = used_capacity;
}