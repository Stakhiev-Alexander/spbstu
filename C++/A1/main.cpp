#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

void testObject(Shape & testedObject)
{
  std::cout << "Area = " << testedObject.getArea() << std::endl;
  std::cout << "Width = " << testedObject.getFrameRect().width << std::endl;
  std::cout << "Height = " << testedObject.getFrameRect().height << std::endl;
  testedObject.move({1.0,2.5});
  std::cout << "X = " << testedObject.getFrameRect().pos.x << std::endl;
  std::cout << "Y = " << testedObject.getFrameRect().pos.y << std::endl;
  testedObject.move(3.5,4.3);
  std::cout << "X = " << testedObject.getFrameRect().pos.x << std::endl;
  std::cout << "Y = " << testedObject.getFrameRect().pos.y << std::endl;
}

int main()
{
  Rectangle myRectangle({5.0, 6.0}, 7.0, 8.0);
  Circle myCircle({10.0, 11.0}, 9.0);

  testObject(myRectangle);
  testObject(myCircle);

return 0;
}
