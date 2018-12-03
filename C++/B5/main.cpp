#include "dataStructVector.hpp"

#include <iostream>

int main()
{
  try
  {
    DataStructVector vector;
    vector.read();
    vector.sort();
    vector.print();
  }
  catch (const std::exception &error)
  {
    std::cerr << error.what()<<std::endl;
    return 1;
  }
  return 0;
}
