#include "circle.hpp"
#include <iostream>
#include <cmath>
#include <stdexcept>

stakhiev::Circle::Circle(const stakhiev::point_t & cent, const double rad):
  center_(cent),
  radius_(rad),
  angle_(0.0)
{
  if (rad < 0.0)
  {
    throw std::invalid_argument("Incorrect coefficient");
  }
  //Invalid value of radius
}

double stakhiev::Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

stakhiev::rectangle_t stakhiev::Circle::getFrameRect() const
{
  return {radius_ * 2, radius_ * 2, center_};
}

void stakhiev::Circle::move(const double dx, const double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void stakhiev::Circle::move(const stakhiev::point_t & newCenter)
{
  center_ = newCenter;
}

void stakhiev::Circle::scale(const double increaseCoefficient)
{
  if (increaseCoefficient < 0.0)
  {
    throw std::invalid_argument("Incorrect coefficient");
  }
  //Invalid value of increase coefficient
  radius_ *= increaseCoefficient;
}

void stakhiev::Circle::rotate(const double angle)
{
  angle_ += angle;
}

void stakhiev::Circle::printName() const
{
  std::cout << " Circle ";
}
