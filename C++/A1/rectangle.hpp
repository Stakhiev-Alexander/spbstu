#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

class Rectangle:
  public Shape
{
public:
  Rectangle(const point_t & cent, const double w, const double h);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const double dx, const double dy) override;
  void move(const point_t & newCenter) override;
private:
  rectangle_t Rect_;
};

#endif
