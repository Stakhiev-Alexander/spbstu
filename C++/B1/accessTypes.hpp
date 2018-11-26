#ifndef ACCESS_TYPES_HPP
#define ACCESS_TYPES_HPP

#include <cstddef>

namespace access
{
  using indexType = std::size_t;

  template <typename T>
  struct AccessByOperator
  {
    indexType getBegin(const T&) const
    {
      return 0;
    }

    indexType getEnd(const T& container) const
    {
      return container.size();
    }

    typename T::reference operator()(T& container, indexType i)
    {
      return container[i];
    }
  };

  template <typename T>
  struct AccessByMethod
  {
    indexType getBegin(const T&) const
    {
      return 0;
    }

    indexType getEnd(const T& container) const
    {
      return container.size();
    }

    typename T::reference operator()(T& container, indexType i)
    {
      return container.at(i);
    }
  };

  template <typename T>
  struct AccessByIterator
  {
    typename T::iterator getBegin(T& container)
    {
      return container.begin();
    }

    typename T::iterator getEnd(T& container)
    {
      return container.end();
    }

    typename T::reference operator()(T&, typename T::iterator i)
    {
      return *i;
    }
  };
}

#endif
