#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

namespace stakhiev
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(const stakhiev::point_t & cent, const double w, const double h);
    double getArea() const override;
    stakhiev::rectangle_t getFrameRect() const override;
    void move(const double dx, const double dy) override;
    void move(const stakhiev::point_t & newCenter) override;
    void scale(const double increaseCoefficient) override;
    void rotate(const double angle) override;
    void printName() const override;
  private:
    stakhiev::rectangle_t Rect_;
    double angle_;
  };
}

#endif
