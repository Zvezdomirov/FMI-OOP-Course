//
// Created by zvezdomirov98 on 24.05.19.
//

#ifndef HOMEWORK_3_POINT3D_H
#define HOMEWORK_3_POINT3D_H

class Point3D {
public:
    explicit Point3D(double x = 0, double y = 0,
                     double z = 0) :
            m_x(x),
            m_y(y),
            m_z(z) {};

    double getX() const;

    void setX(double x);

    double getY() const;

    void setY(double y);

    double getZ() const;

    void setZ(double z);

    virtual double getDistanceTo(const Point3D &);

protected:
    double m_x;
    double m_y;
    double m_z;
};


#endif //HOMEWORK_3_POINT3D_H
