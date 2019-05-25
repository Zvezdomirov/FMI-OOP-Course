//
// Created by zvezdomirov98 on 24.05.19.
//

#ifndef HOMEWORK_3_ENTITY_H
#define HOMEWORK_3_ENTITY_H


#include <string>
#include "Point3D.h"
#include "EntityType.h"

//TODO: Should be abstract class, but Environment can't access it...

class Entity {
public:
    virtual bool isAlive() const { return true; };

    double getDistanceTo2D(const Entity &);

    double getDistanceTo(const Entity &);

    void moveTo(const Point3D &);

    void moveTo(const Entity &);

    int getId() const;

    std::string getName() const;

    void setName(const std::string &name);

    Point3D *getLocation() const;

    void setLocation(const Point3D &);

    EntityType getType() const;



    Entity(std::string name,
           const Point3D &location,
           const EntityType &type);

    Entity(const Entity &); // copy constructor

    Entity &operator=(const Entity &);

    virtual ~Entity();

private:
    static int current_id;
    int m_id;
    std::string m_name;
    Point3D *m_location;
    EntityType m_type;
};


#endif //HOMEWORK_3_ENTITY_H
