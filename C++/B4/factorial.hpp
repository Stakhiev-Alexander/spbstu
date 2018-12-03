#ifndef B4_FACTORIAL_HPP
#define B4_FACTORIAL_HPP

#include <iterator>

class FactorialIterator
  : public std::iterator<std::bidirectional_iterator_tag, unsigned int, unsigned int, unsigned int, unsigned int>
{
public:
  FactorialIterator();

  FactorialIterator(unsigned int n);

  FactorialIterator &operator++();

  FactorialIterator operator++(int);

  FactorialIterator &operator--();

  FactorialIterator operator--(int);

  FactorialIterator::value_type operator*() const;

  bool operator==(const FactorialIterator &rhs) const;

  bool operator!=(const FactorialIterator &rhs) const;

private:
  std::size_t value_;
  std::size_t currentIndex_;
};

class Factorial
{
public:
  using iterator = FactorialIterator;
  using const_iterator = const iterator;
  using value_type = std::size_t;
  using reverse_iterator = std::reverse_iterator<iterator>;
  using const_reverse_iterator = const reverse_iterator;
  using size_type = std::size_t;

  Factorial();

  Factorial(unsigned int size);

  iterator begin() const;

  iterator end() const;

  std::reverse_iterator<iterator> rbegin() const;

  std::reverse_iterator<iterator> rend() const;

private:
  FactorialIterator end_;
};

#endif //B4_FACTORIAL_HPP
