#include <vector>
#include <string>
#include <iostream>
#include <forward_list>

#include "impl.hpp"
#include "accessTypes.hpp"

void firstTask(int argc, char *argv[])
{
  if (argc != 3) {
    throw std::invalid_argument("TASK 1: Wrong number of arguments");
  } else {
    auto comparisonType = detail::getComparisonType<int>(argv[2]);

    std::vector<int> vector1;
    std::vector<int> vector2;

    int i = 0;
    while (std::cin >> i) {
      vector1.push_back(i);
      vector2.push_back(i);
    }

    if ((!std::cin.eof()) && (std::cin.fail())) {
      throw std::invalid_argument("TASK 1: Invalid input data");
    }

    std::forward_list<int> forwardList(vector1.begin(), vector1.end());

    detail::sort(vector1, access::AccessByOperator<std::vector<int>>(), comparisonType);
    detail::sort(vector2, access::AccessByMethod<std::vector<int>>(), comparisonType);
    detail::sort(forwardList, access::AccessByIterator<std::forward_list<int>>(), comparisonType);

    detail::print(vector1);
    detail::print(vector2);
    detail::print(forwardList);
  }
}
