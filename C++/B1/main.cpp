#include <iostream>

#include "tasks.hpp"

int main(int argc, char *argv[])
{
  try {
    if (argc > 1) {
      switch (std::atoi(argv[1])) {
        case 1:
          firstTask(argc, argv);
          break;
        case 2:
          secondTask(argc,argv);
          break;
        case 3:
          thirdTask(argc);
          break;
        case 4:
          fourthTask(argc,argv);
          break;
        default:
          std::cerr << "Incorrect input";
          return 1;
      }
    } else {
      std::cerr << "Not enough arguments";
      return 1;
    }

  }
  catch (const std::exception & ex) {
    std::cerr << ex.what() << '\n';
    return 1;
  }

  return 0;
}
