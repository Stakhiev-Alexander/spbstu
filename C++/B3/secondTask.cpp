#include <string>
#include <iostream>

#include "CommandParser.hpp"

namespace tasks
{
  void print(const std::list<int> &list)
  {
    auto iter1 = list.cbegin();
    auto iter2 = list.cend();
    while (iter1 != iter2) {
      std::cout << *iter1 << ' ';
      iter1++;
      if (iter1 != iter2) {
        iter2--;
        std::cout << *iter2 << ' ';
      }
    }
    std::cout << std::endl;
  }

  void secondTask()
  {
    std::list<int> list;
    std::string tmp;

    while (getline(std::cin, tmp, ' ')) {
      for (char c : tmp) {
        if (!isdigit(c) && (c != '\n') && (c != '\r')) {
          throw std::invalid_argument("Only numbers allowed");
        }
        if (std::stoi(tmp) > 20 || std::stoi(tmp) < 1) {
          throw std::invalid_argument("Numbers must be from 1 to 20");
        }
      }
      list.push_back(std::stoi(tmp));
    }
    if (list.size() > 20) {
      throw std::invalid_argument("Allowed only up to 20 numbers");
    }
    if (!list.empty()) {
      print(list);
    }
  }
}
