#define BOOST_TEST_MODULE main
#define BOOST_TEST_DYN_LINK

#include <boost/test/included/unit_test.hpp>
#include "circle.hpp"
#include "rectangle.hpp"
#include "composite-shape.hpp"
#include "matrix.hpp"

BOOST_AUTO_TEST_SUITE(rotateTests)

  BOOST_AUTO_TEST_CASE(rotateCircle)
  {
    stakhiev::Circle myCircle({5.0, 6.0}, 7.0);
    stakhiev::rectangle_t rectCheck = myCircle.getFrameRect();
    myCircle.rotate(45);
    BOOST_CHECK_EQUAL(myCircle.getFrameRect().pos.x, rectCheck.pos.x);
    BOOST_CHECK_EQUAL(myCircle.getFrameRect().pos.y, rectCheck.pos.y);
  }

  BOOST_AUTO_TEST_CASE(rotateRectangle)
  {
    stakhiev::Rectangle myRectangle({1.0, 2.0}, 3.0, 4.0);
    stakhiev::rectangle_t rectCheck = myRectangle.getFrameRect();
    myRectangle.rotate(45);
    BOOST_CHECK_EQUAL(myRectangle.getArea(), (rectCheck.width * rectCheck.height));
    BOOST_CHECK_EQUAL(myRectangle.getFrameRect().pos.x, rectCheck.pos.x);
    BOOST_CHECK_EQUAL(myRectangle.getFrameRect().pos.y, rectCheck.pos.y);
  }

  BOOST_AUTO_TEST_CASE(rotateCompositeShape)
  {
    std::shared_ptr< stakhiev::Shape > circ1 (new stakhiev::Circle({0.0, 6.0}, 2.0));
    std::shared_ptr< stakhiev::Shape > rect1 (new stakhiev::Rectangle({0.0, 0.0}, 1.0, 1.0));
    std::shared_ptr< stakhiev::Shape > rect2 (new stakhiev::Rectangle({10.0, 10.0}, 1.0, 1.0));
    stakhiev::CompositeShape myComposite(rect1);
    myComposite.add(rect2);
    myComposite.add(circ1);
    stakhiev::rectangle_t rectCheck = myComposite.getFrameRect();
    myComposite.rotate(360);
    BOOST_CHECK_CLOSE(myComposite.getFrameRect().pos.x, rectCheck.pos.x, 0.001);
    BOOST_CHECK_CLOSE(myComposite.getFrameRect().pos.y, rectCheck.pos.y, 0.001);
  }

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(matrixTests)

  BOOST_AUTO_TEST_CASE(testConstructing)
  {
    stakhiev::Matrix myMatrix;
    BOOST_CHECK_EQUAL(myMatrix.getLines(),0);
    BOOST_CHECK_EQUAL(myMatrix.getColumns(),0);
  }

  BOOST_AUTO_TEST_CASE(testInvalingParametrs)
  {
    stakhiev::Matrix myMatrix;
    BOOST_CHECK_THROW(myMatrix.add(nullptr), std::invalid_argument);
    BOOST_CHECK_THROW(myMatrix[-1], std::out_of_range);
    BOOST_CHECK_THROW(myMatrix[5], std::out_of_range);
  }

  BOOST_AUTO_TEST_CASE(testAdding)
  {
    stakhiev::Matrix myMatrix;
    std::shared_ptr< stakhiev::Shape > rect1 (new stakhiev::Rectangle({0.0, 0.0}, 1.0, 1.0));
    std::shared_ptr< stakhiev::Shape > rect2 (new stakhiev::Rectangle({10.0, 10.0}, 1.0, 1.0));
    myMatrix.add(rect1);
    BOOST_CHECK_EQUAL(myMatrix.getLines(),1);
    BOOST_CHECK_EQUAL(myMatrix.getColumns(),1);
    myMatrix.add(rect2);
    BOOST_CHECK_EQUAL(myMatrix.getLines(),2);
    BOOST_CHECK_EQUAL(myMatrix.getColumns(),1);
  }

BOOST_AUTO_TEST_SUITE_END()
