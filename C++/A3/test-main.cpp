#define BOOST_TEST_MODULE main
#define BOOST_TEST_DYN_LINK

#include <boost/test/included/unit_test.hpp>
#include "circle.hpp"
#include "rectangle.hpp"
#include "composite-shape.hpp"

stakhiev::Rectangle myRectangle({8.0, 9.0}, 10.0, 11.0);
std::shared_ptr <stakhiev::Shape> myPtrRectangle = std::make_shared <stakhiev::Rectangle> (myRectangle);

BOOST_AUTO_TEST_SUITE(testCompositeShape)

  BOOST_AUTO_TEST_CASE(testAdding)
  {
    stakhiev::CompositeShape myComposite(myPtrRectangle);
    BOOST_REQUIRE_THROW(myComposite.add(nullptr), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(testAddingEmptyConstructor)
  {
    stakhiev::CompositeShape myCompositeEmpty;
    stakhiev::Circle circ({5.0, 6.0}, 7.0);
    std::shared_ptr <stakhiev::Shape> circPtr = std::make_shared <stakhiev::Circle> (circ);
    myCompositeEmpty.add(circPtr);
    myCompositeEmpty.add(myPtrRectangle);
    BOOST_REQUIRE_THROW(myCompositeEmpty.add(nullptr), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(testScaling)
  {
    stakhiev::CompositeShape myComposite(myPtrRectangle);
    BOOST_CHECK_THROW(myComposite.scale(-2.0), std::invalid_argument);

    stakhiev::Circle circ({5.0, 6.0}, 7.0);
    std::shared_ptr <stakhiev::Shape> circPtr = std::make_shared <stakhiev::Circle> (circ);
    myComposite.add(circPtr);
    stakhiev::rectangle_t rectangleOne = myComposite.getFrameRect();
    myComposite.scale(2.0);
    BOOST_CHECK_EQUAL(myComposite.getFrameRect().pos.x, rectangleOne.pos.x);
    BOOST_CHECK_EQUAL(myComposite.getFrameRect().pos.y, rectangleOne.pos.y);
    BOOST_CHECK_EQUAL(myComposite.getFrameRect().width, rectangleOne.width * 2.0);
    BOOST_CHECK_EQUAL(myComposite.getFrameRect().height, rectangleOne.height * 2.0);

  }

  BOOST_AUTO_TEST_CASE(testInMovingToPoint)
  {
    stakhiev::CompositeShape myComposite(myPtrRectangle);
    stakhiev::rectangle_t rectangleOne = myComposite.getFrameRect();
    double areaOne = myComposite.getArea();

    myComposite.move({1.0,2.5});

    BOOST_CHECK_EQUAL(areaOne, myComposite.getArea());
    BOOST_CHECK_EQUAL(rectangleOne.width, myComposite.getFrameRect().width);
    BOOST_CHECK_EQUAL(rectangleOne.height, myComposite.getFrameRect().height);
  }

  BOOST_AUTO_TEST_CASE(testRectangleInMoving)
  {
    stakhiev::CompositeShape myComposite(myPtrRectangle);
    stakhiev::rectangle_t rectangleOne = myComposite.getFrameRect();
    double areaOne = myComposite.getArea();

    myComposite.move(3.5,4.3);

    BOOST_CHECK_EQUAL(areaOne, myComposite.getArea());
    BOOST_CHECK_EQUAL(rectangleOne.width, myComposite.getFrameRect().width);
    BOOST_CHECK_EQUAL(rectangleOne.height, myComposite.getFrameRect().height);
  }

  BOOST_AUTO_TEST_CASE(testRemoving)
  {
    stakhiev::CompositeShape myComposite(myPtrRectangle);
    stakhiev::Rectangle rect({1.0, 2.0}, 3.0, 4.0);
    stakhiev::Circle circ({5.0, 6.0}, 7.0);
    std::shared_ptr <stakhiev::Shape> rectPtr = std::make_shared <stakhiev::Rectangle> (rect);
    std::shared_ptr <stakhiev::Shape> circPtr = std::make_shared <stakhiev::Circle> (circ);
    myComposite.add(rectPtr);
    myComposite.add(circPtr);
    BOOST_REQUIRE_THROW(myComposite.remove(5), std::invalid_argument);
  }

BOOST_AUTO_TEST_SUITE_END()
