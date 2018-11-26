#include <iostream>
#include <memory>
#include "rectangle.hpp"
#include "circle.hpp"
#include "composite-shape.hpp"
#include "matrix.hpp"

using namespace stakhiev;

using elem_type = std::shared_ptr< Shape >;

using std::cout;
using std::endl;
using std::cerr;

void printShapeInfo(Shape & testedObject)
{
cout << endl;
cout << "Area = " << testedObject.getArea() << endl;
rectangle_t rect = testedObject.getFrameRect();
cout << "x = " << rect.pos.x << endl;
cout << "y = " << rect.pos.y << endl;
cout << "width = " << rect.width << endl;
cout << "height = " << rect.height << endl;
cout << endl;
}

int main()
{
  try
  {
    Rectangle myRectangle({5.0, 6.0}, 7.0, 8.0);
    Circle myCircle({10.0, 11.0}, 9.0);
    cout << "Rectangle:" << endl;
    printShapeInfo(myRectangle);
    myRectangle.rotate(45);
    printShapeInfo(myRectangle);
    myRectangle.rotate(45);
    printShapeInfo(myRectangle);
    myRectangle.rotate(-90);
    cout << "Circle:" << endl;
    printShapeInfo(myCircle);
    myCircle.rotate(45);
    printShapeInfo(myCircle);
    myCircle.rotate(-45);
    elem_type myPtrRectangle = std::make_shared <Rectangle> (myRectangle);
    elem_type myPtrCircle = std::make_shared <Circle> (myCircle);
    cout << "-------------------"<< endl;
    CompositeShape myComposite;
    myComposite.add(myPtrRectangle);
    printShapeInfo(myComposite);
    myComposite.rotate(45);
    printShapeInfo(myComposite);
    myComposite.rotate(45);
    printShapeInfo(myComposite);
    myComposite.add(myPtrCircle);
    myComposite.rotate(45);
    printShapeInfo(myComposite);
    myComposite.rotate(45);
    printShapeInfo(myComposite);
    cout << "-------------------"<< endl;
    Matrix myMatrix;
    myMatrix.add(myPtrCircle);
    myMatrix.draw();
    myMatrix.add(myPtrRectangle);
    myMatrix.draw();
    elem_type rect1 = std::make_shared<Rectangle>(Rectangle({-5.0, 4.0},2.0, 2.0));
    elem_type rect2 = std::make_shared<Rectangle>(Rectangle({-2.0, 4.0},4.0, 2.0));
    elem_type rect3 = std::make_shared<Rectangle>(Rectangle({-3.0, 2.0},6.0, 2.0));
    elem_type rect4 = std::make_shared<Rectangle>(Rectangle({2.0, 1.0},1.0, 1.0));
    elem_type rect5 = std::make_shared<Rectangle>(Rectangle({1.5, 8.0},1.0, 4.0));
    elem_type circ1 = std::make_shared<Circle>(Circle({0.0, 6.0},2.0));
    elem_type circ2 = std::make_shared<Circle>(Circle({3.0, -2.0},5.0));
    elem_type circ3 = std::make_shared<Circle>(Circle({10.0, 1.0},1.0));
    myMatrix.add(rect1);
    myMatrix.add(rect3);
    myMatrix.add(rect2);
    myMatrix.add(rect4);
    myMatrix.add(rect5);
    myMatrix.add(circ1);
    myMatrix.add(circ2);
    myMatrix.add(circ3);
    cout << "-------------------"<< endl;
    myMatrix.draw();
    cout << "Matrix's parametrs: " << endl
         << myMatrix.getLines() << " line, " << myMatrix.getColumns() << " columns" << endl;
  }
  catch (const std::invalid_argument & error)
  {
    cerr << error.what() << endl;
    return 1;
  }
  catch (const std::out_of_range & error)
  {
    cerr << error.what() << endl;
    return 1;
  }
  catch(const std::exception &error)
  {
    cerr << error.what() << endl;
  }


  return 0;
}
