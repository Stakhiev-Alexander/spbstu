#include "dataStructVector.hpp"

#include <iostream>
#include <algorithm>

DataStructVector::DataStructVector()
{
}

void DataStructVector::read()
{
  std::string tmp;
  detail::DataStruct dataStruct;
  while (getline(std::cin, tmp)) {
    tmp = tmp.substr(readKey(tmp, dataStruct.key1) + 1);
    dataStruct.str = tmp.substr(readKey(tmp, dataStruct.key2) + 1);
    dataVector_.push_back(dataStruct);
  }

  if ((!std::cin.eof()) && (std::cin.fail())) {
    throw std::invalid_argument("Failed to read the data");
  }
}

void DataStructVector::sort()
{
  std::sort(dataVector_.begin(), dataVector_.end(), comparator);
}

void DataStructVector::print()
{
  for (auto dataStruct : dataVector_) {
    std::cout << dataStruct.key1 << ',' << dataStruct.key2 << ',' << dataStruct.str << std::endl;
  }
}

bool DataStructVector::comparator(const detail::DataStruct &first, const detail::DataStruct &second)
{
  if (first.key1 < second.key1) {
    return true;
  }
  if (first.key1 == second.key1) {
    if (first.key2 == second.key2) {
      if (first.str.size() == second.str.size()) {
        return (first.str < second.str);
      }
      return (first.str.size() < second.str.size());
    }
    return (first.key2 < second.key2);
  }
  return false;
}

size_t  DataStructVector::readKey(const std::string & line, int & key)
{
  if (line.find_first_of(',') == std::string::npos) {
    throw std::invalid_argument("Must be , after a number");
  }

  key = std::stoi(line.substr(0, line.find_first_of(',')));
  if ((key < detail::keyMinValue) || (key > detail::keyMaxValue)) {
    throw std::invalid_argument("Key must be in between -5 and 5");
  }

  return line.find_first_of(',');
}
