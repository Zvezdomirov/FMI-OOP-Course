//
// Created by zvezdomirov98 on 24.05.19.
//

#include "Point3D.h"
#include <cmath>

double Point3D::getDistanceTo(const Point3D &another) {
    return sqrt(pow(another.m_x - m_x, 2) +
                pow(another.m_y - m_y, 2) +
                pow(another.m_z - m_z, 2));
}

double Point3D::getX() const {
    return m_x;
}

void Point3D::setX(double x) {
    m_x = x;
}

double Point3D::getY() const {
    return m_y;
}

void Point3D::setY(double y) {
    m_y = y;
}

double Point3D::getZ() const {
    return m_z;
}

void Point3D::setZ(const double z) {
    m_z = z;
}
