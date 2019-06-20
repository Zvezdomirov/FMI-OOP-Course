//
// Created by zvezdomirov98 on 24.05.19.
//

#ifndef HOMEWORK_3_POINT2D_H
#define HOMEWORK_3_POINT2D_H


#include "Point3D.h"

/*
 * Basically, in this case it works better
 * if Point2D inherits Point3D, because,
 * although it may be counter-intuitive
 * at first, it makes sense that a 2D point
 * is a 3D one, just with it's z-coordinate set to 0.
 * */
class Point2D : public Point3D {
public:
    explicit Point2D(double x = 0, double y = 0) :
            Point3D(x, y, 0) {};
};


#endif //HOMEWORK_3_POINT2D_H
