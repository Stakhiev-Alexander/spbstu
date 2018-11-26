#include "rectangle.hpp"
#include <iostream>

Rectangle::Rectangle(const point_t & center, const double w, const double h):
  Rect_{w, h, center}
{
  if ((w < 0.0) || (h < 0.0))
  {
    std::cout << "Invalid value of width and/or height" << std::endl;
    exit(1);
  }
}
double Rectangle::getArea() const
{
  return Rect_.width * Rect_.height;
}
rectangle_t Rectangle::getFrameRect() const
{
  return Rect_;
}
void Rectangle::move(const double dx, const double dy)
{
  Rect_.pos.x += dx;
  Rect_.pos.y += dy;
}
void Rectangle::move(const point_t & newCenter)
{
  Rect_.pos = newCenter;
}
