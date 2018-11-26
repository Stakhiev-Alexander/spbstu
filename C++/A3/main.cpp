#include <iostream>
#include <memory>
#include "rectangle.hpp"
#include "circle.hpp"
#include "composite-shape.hpp"

using namespace stakhiev;

using std::cout;
using std::endl;
using std::cerr;

void printShapeInfo(Shape & testedObject)
{
cout << "Area = " << testedObject.getArea() << endl;
rectangle_t rect = testedObject.getFrameRect();
cout << "x = " << rect.pos.x << endl;
cout << "y = " << rect.pos.y << endl;
cout << "width = " << rect.width << endl;
cout << "height = " << rect.height << endl;
}

int main()
{
  Rectangle myRectangle({5.0, 6.0}, 7.0, 8.0);
  Circle myCircle({10.0, 11.0}, 9.0);
  cout << "Rectangle:" << endl;
  printShapeInfo(myRectangle);
  cout << "Circle:" << endl;
  printShapeInfo(myCircle);
  std::shared_ptr <Shape> myPtrRectangle = std::make_shared <Rectangle> (myRectangle);
  std::shared_ptr <Shape> myPtrCircle = std::make_shared <Circle> (myCircle);
  cout << "Test of default constructor:" << endl;
  CompositeShape myCompositeDefault;
  myCompositeDefault.add(myPtrCircle);
  printShapeInfo(myCompositeDefault);
  cout << "Test of constructor with pointer on shape:" << endl;
  CompositeShape myComposite(myPtrRectangle);
  myComposite.add(myPtrCircle);
  cout << "Composite Shape at the beggining:" << endl;
  printShapeInfo(myComposite);
  myComposite.move({12.0,15.0});
  cout << "After moving to point:" << endl;
  printShapeInfo(myComposite);
  myComposite.move(25.0,71.0);
  cout << "After moving by dx, dy:" << endl;
  printShapeInfo(myComposite);
  cout << "After scaling:" << endl;
  myComposite.scale(3.0);
  printShapeInfo(myComposite);
  cout << "After removing one shape:" << endl;
  myComposite.remove(1);
  printShapeInfo(myComposite);
  return 0;
}
