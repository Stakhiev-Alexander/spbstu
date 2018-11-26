#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <memory>
#include "shape.hpp"

namespace stakhiev
{
  class Matrix
  {
  public:
    using elem_type = std::shared_ptr< Shape >;
    using list_type = std::unique_ptr< elem_type[] >;

    Matrix();
    Matrix(const Matrix& matrix);
    Matrix(Matrix& matrix);
    ~Matrix() = default;
    Matrix& operator=(const Matrix& matrix);
    Matrix& operator=(Matrix&& matrix);
    std::unique_ptr<std::shared_ptr<Shape>[]> operator[](const int index) const;
    void add(const elem_type & shape);
    void draw() const;
    int getLines() const;
    int getColumns() const;

  private:
    int columns_;
    int lines_;
    list_type list_;
    bool crossCheck(const elem_type & shapeOne,const elem_type & shapeTwo);
  };
}

#endif
