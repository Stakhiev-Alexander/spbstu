#ifndef B5_DATASTRUCT_HPP
#define B5_DATASTRUCT_HPP

#include <string>

namespace detail
{
  const int keyMaxValue = 5;
  const int keyMinValue = -5;

  struct DataStruct
  {
    int key1;
    int key2;
    std::string str;
  };
}

#endif
