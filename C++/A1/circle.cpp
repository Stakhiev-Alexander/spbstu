#include "circle.hpp"
#include <iostream>
#include <cmath>

Circle::Circle(const point_t & center, const double rad):
  center_(center),
  radius_(rad)
{
  if (rad < 0.0)
  {
    std::cout << "Invalid value of radius" << std::endl;
    exit(1);
  }
}
double Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}
rectangle_t Circle::getFrameRect() const
{
  return {radius_ * 2, radius_ * 2, center_};
}
void Circle::move(const double dx, const double dy)
{
  center_.x += dx;
  center_.y += dy;
}
void Circle::move(const point_t & newCenter)
{
  center_ = newCenter;
}
