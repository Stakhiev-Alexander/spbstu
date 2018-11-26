#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.hpp"

namespace stakhiev
{
  class Shape
  {
  public:
    virtual ~Shape() = default;
    virtual double getArea() const = 0;
    virtual stakhiev::rectangle_t getFrameRect() const = 0;
    virtual void move(const double dx, const double dy) = 0;
    virtual void move(const stakhiev::point_t & newCenter) = 0;
    virtual void scale(const double increaseCoefficient) = 0;
    virtual void rotate(const double angle) = 0;
    virtual void printName() const = 0;
  };
}

#endif
