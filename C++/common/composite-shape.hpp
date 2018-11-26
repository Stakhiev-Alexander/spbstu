#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP
#include <memory>
#include "shape.hpp"

namespace stakhiev
{
  class CompositeShape : public Shape
  {
  public:
    using elem_type = std::shared_ptr< Shape >;
    using list_type = std::unique_ptr< elem_type[] >;

    //Default constructor
    CompositeShape();
    //Constructor with pointer on shape to add
    CompositeShape(const elem_type newShape);
    const Shape& operator [](const size_t index) const;
    double getArea() const override;
    stakhiev::rectangle_t getFrameRect() const override;
    void move(double dx, double dy) override;
    void move(const stakhiev::point_t & newCenter) override;
    void scale(const double increaseCoefficient) override;
    void rotate(const double angle) override;
    void printName() const override;

    void add(const elem_type newShape);
    void remove(const size_t index);
  private:
    size_t size_;
    double angle_;
    //Array of pointers on shapes
    list_type list_;
  };
}

#endif
