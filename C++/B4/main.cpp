#include <iostream>

#include "tasks.hpp"

int main(int argc, char** argv)
{
  try {
    if (argc != 2) {
      std::cerr << "Must be 2 arguments";
      return 1;
    }
    switch (std::stoi(argv[1])) {
      case 1:
        tasks::firstTask();
        break;
      case 2:
        tasks::secondTask();
        break;
      default:
        std::cerr << "1 or 2 are only allowed numbers";
        return 1;
    }
  }
  catch (const std::invalid_argument &error) {
    std::cerr << error.what();
    return 1;
  }
  return 0;
}
