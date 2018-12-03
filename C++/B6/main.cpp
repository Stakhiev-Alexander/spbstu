#include <iostream>
#include <string>
#include "task.hpp"

int main(int argc, char ** argv)
{
  try {
    if (argc != 2) {
      throw std::invalid_argument("Invalid number of input parameters");
    }

    int number = std::stoi(argv[1]);
    switch (number) {
      case 1:
        task1();
        break;

      case 2:
        task2();
        break;

      default:
        throw std::invalid_argument("Invalid value of input parameter");
    }
  }
  catch (std::exception & e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }
  catch (...) {
    std::cerr << "Something was wrong" << std::endl;
    return 2;
  }
  return 0;
}
