#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

void testObject(stakhiev::Shape & testedObject)
{
  std::cout << "Area = " << testedObject.getArea() << std::endl;
  testedObject.scale(2.0);
  std::cout << "Area = " << testedObject.getArea() << std::endl;
}

int main()
{
  stakhiev::Rectangle myRectangle({5.0, 6.0}, 7.0, 8.0);
  stakhiev::Circle myCircle({10.0, 11.0}, 9.0);

  testObject(myRectangle);
  testObject(myCircle);

  return 0;
}
