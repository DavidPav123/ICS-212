#include "Circle.h"
#include <iostream>

int main()
{
    int x = 0,y = 0, radius;
    int& x_ref = x, &y_ref = y;

    Circle thing;
    thing.setRadius(10);
    thing.setPos(5, 10);
    radius = thing.getRadius();
    thing.getPos(x_ref, y_ref);
    std::cout<<"Radius:"<<radius<<std::endl;
    std::cout<<"X:"<<x<<std::endl;
    std::cout<<"Y:"<<y<<std::endl;
}
