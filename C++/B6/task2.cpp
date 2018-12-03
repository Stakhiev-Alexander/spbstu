#include <iostream>
#include <sstream>
#include <list>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>

struct Point
{
  int x, y;
};

using Shape = std::vector<Point>;

std::ostream &operator<<(std::ostream &out, const Point &point)
{
  out << " (" << point.x << "; " << point.y << ")";
  return out;
}

std::ostream &operator<<(std::ostream &out, const Shape &shape)
{
  out << shape.size();
  std::copy(shape.begin(), shape.end(), std::ostream_iterator<Point>(out));

  return out;
}

std::istream &operator>>(std::istream &in, Shape &shape)
{
  shape.clear();
  std::string buff;
  std::stringstream sstr;
  std::string num;
  while (num.empty()) {
    std::getline(in, buff);
    if (in.eof() && buff.empty()) {
      return in;
    }
    sstr = std::stringstream(buff);
    sstr >> num;
  }
  for (int n = std::stoi(num); n > 0; n--) {
    if (sstr.eof()) {
      throw std::invalid_argument("Invalid point count.");
    }
    sstr >> std::ws;
    std::getline(sstr, buff, ')');
    sstr.get();
    if (buff.find('(') != 0 && buff.find(';') > buff.size()) {
      throw std::invalid_argument("Invalid input.");
    }
    num.assign(buff, buff.find('(') + 1, buff.find(';') - buff.find('('));
    int x = std::stoi(num);
    num.assign(buff, buff.find(';') + 1, buff.size() - 1);
    int y = std::stoi(num);
    shape.push_back({x, y});
  }
  sstr >> std::ws;
  if (!sstr.eof()) {
    throw std::invalid_argument("Invalid point count.");
  }
  return in;
}

bool isSquare(const Shape &shape)
{
  if (shape.size() != 4) {
    return false;
  } else
    return !((std::abs(shape.at(1).x - shape.at(0).x) != std::abs(shape.at(2).y - shape.at(1).y)) ||
             (std::abs(shape.at(2).x - shape.at(1).x) != std::abs(shape.at(1).y - shape.at(0).y)));
}

void task2()
{
  std::list<Shape> shapes;
  size_t shapeCount[3]{0, 0, 0};
  size_t vertices = 0;
  std::copy(std::istream_iterator<Shape>(std::cin), std::istream_iterator<Shape>(),
            std::insert_iterator<std::list<Shape>>(shapes, shapes.begin()));
  std::for_each(shapes.begin(), shapes.end(), [&](const Shape &shape)
  {
      vertices += shape.size();
      if (shape.size() == 3) {
        shapeCount[0]++;
      } else if (isSquare(shape)) {
        shapeCount[1]++;
        shapeCount[2]++;
      } else if (shape.size() == 4) {
        shapeCount[2]++;
      }
  });
  shapes.remove_if([](const Shape &shape)
                   {
                       return shape.size() == 5;
                   });
  std::vector<Point> pointVect;
  std::for_each(shapes.begin(), shapes.end(), [& pointVect](const Shape &shape)
  {
      pointVect.push_back(shape[0]);
  });
  auto triangleBorder = std::stable_partition(shapes.begin(), shapes.end(),
                                              [](const Shape &shape) { return shape.size() == 3; });
  std::stable_partition(triangleBorder, shapes.end(), [](const Shape &shape) { return isSquare(shape); });


  std::cout << "Vertices: " << vertices << "\n";
  std::cout << "Triangles: " << shapeCount[0] << "\n";
  std::cout << "Squares: " << shapeCount[1] << "\n";
  std::cout << "Rectangles: " << shapeCount[2] << "\n";
  std::cout << "Points:";
  std::copy(pointVect.begin(), pointVect.end(), std::ostream_iterator<Point>(std::cout));
  std::cout << "\n";
  std::cout << "Shapes:" << "\n";
  std::copy(shapes.begin(), shapes.end(), std::ostream_iterator<Shape>(std::cout, "\n"));
}
