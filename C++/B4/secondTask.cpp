#include <iostream>
#include "tasks.hpp"
#include "factorial.hpp"

void tasks::secondTask()
{
  Factorial factorial;
      std::copy(factorial.begin(), factorial.end(), std::ostream_iterator<int>(std::cout, " "));
      std::cout << '\n';
      std::copy(std::reverse_iterator<FactorialIterator>(factorial.end()),
                std::reverse_iterator<FactorialIterator>(factorial.begin()),
                std::ostream_iterator<int>(std::cout, " "));
      std::cout << '\n';
}
