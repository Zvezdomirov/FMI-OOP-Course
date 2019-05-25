//
// Created by zvezdomirov98 on 24.05.19.
//

#ifndef HOMEWORK_3_POINT2D_H
#define HOMEWORK_3_POINT2D_H


#include "Point3D.h"

class Point2D : public Point3D {
public:
    explicit Point2D(double x = 0, double y = 0) :
            Point3D(x, y, 0) {};
};


#endif //HOMEWORK_3_POINT2D_H
