#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "shape.hpp"

namespace stakhiev
{
  class Circle : public Shape
  {
  public:
    Circle(const point_t & center, const double radius);
    double getArea() const override;
    stakhiev::rectangle_t getFrameRect() const override;
    void move(const double dx, const double dy) override;
    void move(const stakhiev::point_t & newCenter) override;
    void scale(const double increaseCoefficient) override;
    void rotate(const double angle) override;
    void printName() const override;
  private:
    stakhiev::point_t center_;
    double radius_;
    double angle_;
  };
}

#endif
