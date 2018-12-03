#include "task.hpp"

#include <set>
#include <string>
#include <iostream>


void task1()
{
  std::set<std::string> setWords;
  std::string buf;
  while (std::cin >> buf)
  {
    setWords.insert(buf);
  }
  for (const auto& word : setWords)
  {
    std::cout << word << std::endl;
  }
}
