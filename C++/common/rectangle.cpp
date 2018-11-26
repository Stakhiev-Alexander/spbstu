#include "rectangle.hpp"
#include <iostream>
#include <stdexcept>
#include <cmath>

stakhiev::Rectangle::Rectangle(const stakhiev::point_t & cent, const double w, const double h):
  Rect_{w, h, cent},
  angle_(0.0)
{
  if ((w < 0.0) || (h < 0.0))
  {
    throw std::invalid_argument("Incorrect coefficient");
  }
  //Invalid value of width and/or height
}

double stakhiev::Rectangle::getArea() const
{
  return Rect_.width * Rect_.height;
}

stakhiev::rectangle_t stakhiev::Rectangle::getFrameRect() const
{
  double height = std::abs(Rect_.height*cos(angle_*M_PI/180)) + std::abs(Rect_.width*sin(angle_*M_PI/180));
  double width = std::abs(Rect_.width*cos(angle_*M_PI/180)) + std::abs(Rect_.height*sin(angle_*M_PI/180));

  return {width, height, Rect_.pos};
}

void stakhiev::Rectangle::move(const double dx, const double dy)
{
  Rect_.pos.x += dx;
  Rect_.pos.y += dy;
}

void stakhiev::Rectangle::move(const stakhiev::point_t & newCenter)
{
  Rect_.pos = newCenter;
}

void stakhiev::Rectangle::scale(const double increaseCoefficient)
{
  if (increaseCoefficient < 0.0)
  {
    throw std::invalid_argument("Incorrect coefficient");
  }
  //Invalid value of increase coefficient
  Rect_.width *= increaseCoefficient;
  Rect_.height *= increaseCoefficient;
}

void stakhiev::Rectangle::rotate(const double angle)
{
  angle_ += angle;
}

void stakhiev::Rectangle::printName() const
{
  std::cout << " Rectanlge ";

}
