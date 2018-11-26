#define BOOST_TEST_MODULE main
#define BOOST_TEST_DYN_LINK

#include <stdexcept>
#include <boost/test/included/unit_test.hpp>
#include "circle.hpp"
#include "rectangle.hpp"

BOOST_AUTO_TEST_SUITE(MovingToPointTests)

  BOOST_AUTO_TEST_CASE(testRectangleInMovingToPoint)
  {
    stakhiev::Rectangle myRectangle({5.0, 6.0}, 7.0, 8.0);
    stakhiev::rectangle_t rectangleOne = myRectangle.getFrameRect();
    double areaOne = myRectangle.getArea();

    myRectangle.move({1.0,2.5});

    BOOST_CHECK_EQUAL(areaOne, myRectangle.getArea());
    BOOST_CHECK_EQUAL(rectangleOne.width, myRectangle.getFrameRect().width);
    BOOST_CHECK_EQUAL(rectangleOne.height, myRectangle.getFrameRect().height);
  }

  BOOST_AUTO_TEST_CASE(testCircleInMovingToPoint)
  {
    stakhiev::Circle myCircle({10.0, 11.0}, 9.0);
    stakhiev::rectangle_t circleOne = myCircle.getFrameRect();
    double areaOne = myCircle.getArea();

    myCircle.move({1.0,2.5});

    BOOST_CHECK_EQUAL(areaOne, myCircle.getArea());
    BOOST_CHECK_EQUAL(circleOne.width, myCircle.getFrameRect().width);
    BOOST_CHECK_EQUAL(circleOne.height, myCircle.getFrameRect().height);
  }

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(MovingTests)

  BOOST_AUTO_TEST_CASE(testRectangleInMoving)
  {
    stakhiev::Rectangle myRectangle({5.0, 6.0}, 7.0, 8.0);
    stakhiev::rectangle_t rectangleOne = myRectangle.getFrameRect();
    double areaOne = myRectangle.getArea();

    myRectangle.move(3.5,4.3);

    BOOST_CHECK_EQUAL(areaOne, myRectangle.getArea());
    BOOST_CHECK_EQUAL(rectangleOne.width, myRectangle.getFrameRect().width);
    BOOST_CHECK_EQUAL(rectangleOne.height, myRectangle.getFrameRect().height);
  }

  BOOST_AUTO_TEST_CASE(testCircleInMoving)
  {
    stakhiev::Circle myCircle({10.0, 11.0}, 9.0);
    stakhiev::rectangle_t circleOne = myCircle.getFrameRect();
    double areaOne = myCircle.getArea();

    myCircle.move(3.5,4.3);

    BOOST_CHECK_EQUAL(areaOne, myCircle.getArea());
    BOOST_CHECK_EQUAL(circleOne.width, myCircle.getFrameRect().width);
    BOOST_CHECK_EQUAL(circleOne.height, myCircle.getFrameRect().height);
  }

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(ScalingTests)

  BOOST_AUTO_TEST_CASE(testRectangleInScaling)
  {
    stakhiev::Rectangle myRectangle({5.0, 6.0}, 7.0, 8.0);
    double areaOne = myRectangle.getArea();

    myRectangle.scale(2.0);

    BOOST_CHECK_CLOSE(2.0 * 2.0 * areaOne, myRectangle.getArea(), 0.001);
  }

  BOOST_AUTO_TEST_CASE(testCircleInScaling)
  {
    stakhiev::Circle myCircle({10.0, 11.0}, 9.0);
    double areaOne = myCircle.getArea();

    myCircle.scale(2.0);

    BOOST_CHECK_CLOSE(2.0 * 2.0 * areaOne, myCircle.getArea(), 0.001);
  }

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(ParametersTests)

  BOOST_AUTO_TEST_CASE(testRectangleParameters)
  {
    BOOST_CHECK_THROW( stakhiev::Rectangle({5.0, 6.0}, 7.0, -8.0), std::invalid_argument );
    BOOST_CHECK_THROW( stakhiev::Rectangle({5.0, 6.0}, -7.0, 8.0), std::invalid_argument );
    BOOST_CHECK_THROW( stakhiev::Rectangle({5.0, 6.0}, -7.0, -8.0), std::invalid_argument );
  }

  BOOST_AUTO_TEST_CASE(testCircleParameters)
  {
    BOOST_CHECK_THROW( stakhiev::Circle({10.0, 11.0}, -9.0), std::invalid_argument );
  }

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(IncreaseCoefficientTests)

  BOOST_AUTO_TEST_CASE(testIncreaseCoefficientInRectangle)
  {
    stakhiev::Rectangle myRectangle({5.0, 6.0}, 7.0, 8.0);
    BOOST_CHECK_THROW( myRectangle.scale(-2.0), std::invalid_argument );
  }

  BOOST_AUTO_TEST_CASE(testIncreaseCoefficientInCircle)
  {
    stakhiev::Circle myCircle({10.0, 11.0}, 9.0);
    BOOST_CHECK_THROW( myCircle.scale(-2.0), std::invalid_argument );
  }

BOOST_AUTO_TEST_SUITE_END()
