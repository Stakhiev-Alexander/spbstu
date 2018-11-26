#include "composite-shape.hpp"
#include <iostream>
#include <stdexcept>
#include <cmath>

stakhiev::CompositeShape::CompositeShape():
  size_(0),
  list_(nullptr)
{
}

stakhiev::CompositeShape::CompositeShape(const elem_type newShape):
  size_(0),
  list_(nullptr)
{
  if (!newShape)
  {
    throw std::invalid_argument("Invalid pointer");
  }
  add(newShape);
}

const stakhiev::Shape& stakhiev::CompositeShape::operator[](const size_t index) const
{
  if (index >= size_)
  {
    throw std::out_of_range("Index is out of range");
  }
  return *list_[index];
}

double stakhiev::CompositeShape::getArea() const
{
  double area = 0.0;
  for (size_t i = 0; i < size_; ++i)
  {
    area += list_[i] -> getArea();
  }
  return area;
}

stakhiev::rectangle_t stakhiev::CompositeShape::getFrameRect() const
{
  if (size_ == 0)
  {
    return {0.0, 0.0, {0.0, 0.0}};
  }
  stakhiev::rectangle_t tempRectangle = list_[0] -> getFrameRect();
  double minX = tempRectangle.pos.x - tempRectangle.width/2;
  double maxX = tempRectangle.pos.x + tempRectangle.width/2;
  double minY = tempRectangle.pos.y - tempRectangle.height/2;
  double maxY = tempRectangle.pos.y + tempRectangle.height/2;
  for (size_t i = 0; i < size_; ++i)
  {
    tempRectangle = list_[i] -> getFrameRect();
    if (tempRectangle.pos.x - tempRectangle.width / 2 < minX)
    {
      minX = tempRectangle.pos.x - tempRectangle.width / 2;
    }
    if (tempRectangle.pos.x + tempRectangle.width / 2 > maxX)
    {
      maxX = tempRectangle.pos.x + tempRectangle.width / 2;
    }
    if (tempRectangle.pos.y - tempRectangle.height / 2 < minY)
    {
      minY = tempRectangle.pos.y - tempRectangle.height / 2;
    }
    if (tempRectangle.pos.y + tempRectangle.height / 2 > maxY)
    {
      maxY = tempRectangle.pos.y + tempRectangle.height / 2;
    }
  }
  return { maxX - minX, maxY - minY, {minX + (maxX - minX) / 2, minY + (maxY - minY) / 2} };
}

void stakhiev::CompositeShape::move(double dx, double dy)
{
  for (size_t i = 0; i < size_; ++i)
  {
    list_[i]->move(dx, dy);
  }
}

void stakhiev::CompositeShape::move(const stakhiev::point_t & newCenter)
{
  for (size_t i = 0; i < size_; ++i)
  {
    list_[i]->move((newCenter.x - getFrameRect().pos.x), (newCenter.y - getFrameRect().pos.y));
  }
}

void stakhiev::CompositeShape::scale(const double increaseCoefficient)
{
  if (increaseCoefficient < 0.0)
  {
    throw std::invalid_argument("Incorrect coefficient");
  }
  point_t currentPos = getFrameRect().pos;
  for (size_t i = 0; i < size_; ++i)
  {
    list_[i]->move((increaseCoefficient - 1) * (list_[i]->getFrameRect().pos.x - currentPos.x), (increaseCoefficient - 1)
      * (list_[i]->getFrameRect().pos.y - currentPos.y));
    list_[i] -> scale(increaseCoefficient);
  }
}

void stakhiev::CompositeShape::add(const elem_type newShape)
{
  if (!newShape)
  {
    throw std::invalid_argument("Empty pointer");
  }
  list_type tmp(new elem_type [size_ + 1]);
  for (size_t i = 0; i < size_; ++i)
  {
    tmp[i] = list_[i];
  }
  tmp[size_] = newShape;
  size_++;
  list_.swap(tmp);
}

void stakhiev::CompositeShape::remove(const size_t index)
{
  if ((size_ == 0) || (index >= size_))
  {
    throw std::invalid_argument("Index does not exist");
  }
  list_type tmp(new elem_type [size_ - 1]);
  for (size_t i = 0; i < index; i++)
  {
    tmp[i] = list_[i];
  }
  for (size_t i = index; i < size_ - 1; ++i)
  {
    tmp[i] = list_[i + 1];
  }
  list_.swap(tmp);
  size_--;
}

void stakhiev::CompositeShape::rotate(const double angle)
{
  angle_ += angle;
  stakhiev::point_t center = getFrameRect().pos;
  double cosAngle = cos(angle * M_PI / 180.0);
  double sinAngle = sin(angle * M_PI / 180.0);

  for (size_t i = 0; i < size_; i++)
  {
    const stakhiev::point_t centerShape = list_[i] -> getFrameRect().pos;
    stakhiev::point_t newPos = {0, 0};
    newPos.x = center.x + (centerShape.x - center.x) * cosAngle - (centerShape.y - center.y) * sinAngle;
    newPos.y = center.y + (centerShape.y - center.y) * cosAngle + (centerShape.x - center.x) * sinAngle;

    list_[i]->move(newPos);
    list_[i] -> rotate(angle);
  }
}

void stakhiev::CompositeShape::printName() const
{
  std::cout << " CompositeShape ";
}
