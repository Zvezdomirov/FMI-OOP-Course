#include <utility>

#include <utility>

#include <utility>

#include <utility>

//
// Created by zvezdomirov98 on 24.05.19.
//

#include "Entity.h"
#include "Point2D.h"

int Entity::current_id = 0;

Entity::Entity(std::string name,
               const Point3D &location,
               const EntityType &type) :
        m_id(current_id++),
        m_name(std::move(name)),
        m_location(nullptr),
        m_type(type) {
    setLocation(location);
}

Entity::Entity(const Entity &copy) {
    m_id = copy.m_id;
    m_name = copy.m_name;
    m_location = nullptr;
    setLocation(*copy.m_location);
    m_type = copy.m_type;
}

Entity &Entity::operator=(const Entity &rhs) {
    if (this != &rhs) {
        m_id = rhs.m_id;
        m_name = rhs.m_name;
        delete m_location;
        m_location = nullptr;
        setLocation(*rhs.m_location);
        m_type = rhs.m_type;
    }
    return *this;
}

void Entity::setLocation(const Point3D &location) {
    delete m_location;
    m_location = new Point3D(location.getX(),
                             location.getY(),
                             location.getZ());
}

int Entity::getId() const {
    return m_id;
}

std::string Entity::getName() const {
    return m_name;
}

void Entity::setName(const std::string &name) {
    m_name = name;
}

Point3D *Entity::getLocation() const {
    return m_location;
}

EntityType Entity::getType() const {
    return m_type;
}

Entity::~Entity() {
    delete m_location;
}

double Entity::getDistanceTo2D(const Entity &another) {
    Point2D thisLoc(m_location->getX(), m_location->getY());
    Point2D otherLoc(another.m_location->getX(),
                     another.m_location->getY());

    return thisLoc.getDistanceTo(otherLoc);
}

double Entity::getDistanceTo(const Entity &another) {
    //Check if at least one point is on the 2D plane
    if (m_location->getZ() == 0 ||
        another.m_location->getZ() == 0) {
        return this->getDistanceTo2D(another);
    } else {
        return m_location->getDistanceTo(*another.m_location);
    }
}

void Entity::moveTo(const Point3D &another) {
    setLocation(another);
}

void Entity::moveTo(const Entity &another) {
    setLocation(*another.m_location);
}
