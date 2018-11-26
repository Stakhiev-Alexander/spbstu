#include <vector>
#include <iostream>

#include "impl.hpp"

void thirdTask(int argc)
{
  if (argc != 2) {
    throw std::invalid_argument("TASK 3: Wrong number of arguments");
  }

  std::vector<int> vector;
  int i = 0;
  while (std::cin >> i) {
    vector.push_back(i);
  }

  if (!std::cin.eof() && (std::cin.fail())) {
    throw std::invalid_argument("TASK 3: Invalid input data");
  }

  if (vector.empty()) {
    return;
  }

  if (vector.back() != 0) {
    throw std::invalid_argument("TASK 3: Data must end with zero");
  } else {
    vector.pop_back();
  }

  if (vector.empty()) {
    return;
  }

  auto iter = vector.begin();
  if (vector.back() == 1) {
    while (iter != vector.end()) {
      if ((*iter % 2) == 0) {
        vector.erase(iter);
      } else {
        iter ++;
      }
    }
  } else if (vector.back() == 2) {
    while (iter != vector.end()) {
      if ((*iter % 3) == 0) {
        iter = vector.insert(++iter, 3, 1);
        iter += 2;
      }
      iter++;
    }
  }

  detail::print(vector);
}
