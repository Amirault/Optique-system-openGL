#include "Point.h"

Point::Point(double valX = 0, double valY = 0, double valZ = 0)
{
    //ctor
    x = valX;
    y = valY;
    z = valZ;
}

Point::~Point()
{
    //dtor
}

Point::Point(const Point& other)
{
    //copy ctor
}
