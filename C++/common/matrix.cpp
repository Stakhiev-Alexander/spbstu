#include "matrix.hpp"
#include <memory>
#include <iostream>
#include <cmath>
#include "shape.hpp"

stakhiev::Matrix::Matrix():
  columns_(0),
  lines_(0),
  list_(nullptr)
{
}

stakhiev::Matrix::Matrix(const stakhiev::Matrix& matrix):
  columns_(matrix.columns_),
  lines_(matrix.lines_),
  list_(new elem_type [matrix.columns_ * matrix.lines_])
{
  for (int i = 0; i < matrix.columns_ * matrix.lines_; i++)
  {
    list_[i] = matrix.list_[i];
  }
}

stakhiev::Matrix::Matrix(stakhiev::Matrix& matrix):
  columns_(matrix.columns_),
  lines_(matrix.lines_),
  list_(std::move(matrix.list_))
{
  matrix.columns_ = 0;
  matrix.lines_ = 0;
}

stakhiev::Matrix& stakhiev::Matrix::operator=(const Matrix& matrix)
{
  if (this == &matrix)
  {
    return *this;
  }

  list_.reset(new elem_type[matrix.lines_ * matrix.columns_]);
  lines_ = matrix.lines_;
  columns_ = matrix.columns_;
  for (int i = 0; i < lines_ * columns_; i++)
  {
    list_[i] = matrix.list_[i];
  }
  return *this;
}

stakhiev::Matrix& stakhiev::Matrix::operator=(Matrix&& matrix)
{
  list_ = std::move(matrix.list_);
  lines_ = matrix.lines_;
  columns_ = matrix.columns_;
  for (int i = 0; i < lines_ * columns_; i++)
  {
    list_[i] = matrix.list_[i];
  }
  return *this;
}

std::unique_ptr<std::shared_ptr<stakhiev::Shape>[]> stakhiev::Matrix::operator[](const int index) const
{
  if (index >= lines_ || index < 0)
  {
    throw std::out_of_range("Index is out of range");
  }

  list_type array(new elem_type[columns_]);

  for (int i = 0; i < lines_; i++)
  {
    array[i] = list_[index * lines_ * i];
  }
  return array;
}

void stakhiev::Matrix::add(const elem_type & shape)
{
  if (shape == nullptr) {
    throw std::invalid_argument("Invalid pointer");
  }
  if ((columns_ == 0) && (lines_ == 0))
  {
    list_type newMatrix(new elem_type[1]);
    lines_++;
    columns_++;
    newMatrix[0] = shape;
    list_.swap(newMatrix);
    return;
  }
  int i = 0;
  for (; i < columns_; i++)
  {
    int j = 0;
    for(; j < lines_; j++)
    {
      if (list_[i * lines_ + j] == nullptr)
      {
        list_[i * lines_ + j] = shape;
        return;
      }
      if (crossCheck(list_[i * lines_ + j], shape))
      {
        break;
      }
    }
    if (j == lines_)
    {
      list_type newMatrix(new elem_type [columns_ * (lines_ + 1)]);
      for (int k = 0; k < columns_; k++)
      {
        for (j = 0; j < lines_; j++)
        {
          newMatrix[k * lines_ + j + k] = list_[k * lines_ + j];
        }
      }
      ++lines_;
      newMatrix[(i + 1) * lines_ - 1] = shape;
      list_.swap(newMatrix);
      return;
    }
  }
  if (i == columns_)
  {
    list_type newMatrix(new elem_type [(columns_+1) * (lines_)]);
    for (int k = 0; k < columns_ * lines_; k++) {
      newMatrix[k] = list_[k];
    }
    newMatrix[columns_ * lines_] = shape;
    columns_++;
    list_.swap(newMatrix);
  }
}

void stakhiev::Matrix::draw() const
{
  for (int i = 0; i < lines_; i++)
  {
    for (int j = 0; j < columns_; j++)
    {
      if (list_[i * columns_ + j] != nullptr)
      {
        list_[i * columns_ + j]->printName();
      }
    }
    std::cout << std::endl;
  }
}

int stakhiev::Matrix::getLines() const
{
  return lines_;
}

int stakhiev::Matrix::getColumns() const
{
  return columns_;
}

bool stakhiev::Matrix::crossCheck(const elem_type & shapeOne, const elem_type & shapeTwo)
{
  {
    if (shapeOne == nullptr || shapeTwo == nullptr)
    {
      throw std::invalid_argument("Invalid pointer");
    }
    stakhiev::rectangle_t rectOne = shapeOne->getFrameRect();
    stakhiev::rectangle_t rectTwo = shapeTwo->getFrameRect();
    return ((fabs(rectOne.pos.x - rectTwo.pos.x) < rectOne.width / 2 + rectTwo.width / 2)
              && fabs(rectOne.pos.y - rectTwo.pos.y) < rectOne.height / 2 + rectTwo.height / 2);
  }
}
