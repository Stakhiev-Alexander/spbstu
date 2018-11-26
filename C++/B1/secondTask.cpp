#include <vector>
#include <fstream>
#include <memory>
#include <iostream>

#include "impl.hpp"

void secondTask(int argc, char *argv[])
{
  if (argc != 3) {
    throw std::invalid_argument("TASK 2: Wrong number of arguments");
  } else {
    std::ifstream file(argv[2]);
    if (!file) {
      throw std::invalid_argument("TASK 2: Invalid arguments");
    } else {
      file.seekg(0, std::ios_base::end);
      const auto length = file.tellg();
      file.seekg(0);

      std::unique_ptr<char[]> arr(new char[length]);
      file.read(arr.get(), length);
      std::vector<char> vector(arr.get(), arr.get() + length);

      for (auto i = vector.begin(); i != vector.end(); i++) {
        std::cout << *i;
      }
    }
  }
}
