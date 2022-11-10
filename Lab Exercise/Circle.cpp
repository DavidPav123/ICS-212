#include "Circle.h"

void Circle::setRadius(int value) { radius = value; }

int Circle::getRadius() { return radius; }

void Circle::setPos(int x_val, int y_val) {
  x = x_val;
  y = y_val;
}

void Circle::getPos(int& x_val, int& y_val)
{
    x_val = x;
    y_val = y;
}

Circle::Circle() {
  radius = 0;
  x = 0;
  y = 0;
}
Circle::~Circle() {}
