#ifndef IMPL_HPP
#define IMPL_HPP

#include <iostream>
#include <cstring>
#include <functional>

namespace detail
{
  template<typename T>
  void print(T& container)
  {
    for(typename T::iterator i = container.begin(); i != container.end(); i++) {
      std::cout << *i << " ";
    }
    std::cout << '\n';
  }

  template<typename ContainerT, typename AccessT, typename CompareT>
  void sort(ContainerT& container, AccessT access, CompareT compare)
  {
    for (auto i = access.getBegin(container); i != access.getEnd(container); i++) {
      for (auto j = i; j != access.getEnd(container); j++) {
        if (compare(access(container, i), access(container, j))) {
          std::swap(access(container, i), access(container, j));
        }
      }
    }
  }

  template<typename T>
  std::function <bool(const T&, const T&)> getComparisonType (const char *sortType)
  {
    if (std::strcmp(sortType, "ascending") == 0) {
      return std::greater<T>();
    }
    if (std::strcmp(sortType, "descending") == 0) {
      return std::less<T>();
    } else {
      throw std::invalid_argument("Wrong input: invalid sort type");
    }
  }
}

#endif
