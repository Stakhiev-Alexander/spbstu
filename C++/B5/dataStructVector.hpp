#ifndef B5_DATASTRUCTVECTOR_HPP
#define B5_DATASTRUCTVECTOR0_HPP

#include <vector>

#include "dataStruct.hpp"

class DataStructVector
{
public:
  DataStructVector();
  void read();
  void sort();
  void print();
private:
  std::vector<detail::DataStruct> dataVector_;
  static bool comparator(const detail::DataStruct &, const detail::DataStruct &);
  size_t readKey(const std::string & line, int & key);
};

#endif
