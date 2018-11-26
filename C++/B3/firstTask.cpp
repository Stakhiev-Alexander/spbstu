#include <string>
#include <iostream>

#include "CommandParser.hpp"

namespace tasks
{
  void firstTask()
  {
    std::string tmp;
    std::string str;
    while (getline(std::cin, tmp)) {
      str += tmp;
      str += '\n';
    }

    if ((!std::cin.eof()) && (std::cin.fail())) {
      throw std::invalid_argument("Failed to read the data");
    }

    detail::commandParser(str);
  }
}
