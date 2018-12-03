#include "factorial.hpp"

FactorialIterator::FactorialIterator() :
  FactorialIterator(1) {}

FactorialIterator::FactorialIterator(const unsigned int n) :
  value_(1),
  currentIndex_(n)
{
  for (std::size_t i = 2; i <= n; ++i) {
    value_ *= i;
  }
}

FactorialIterator &FactorialIterator::operator++()
{
  value_ *= ++currentIndex_;
  return *this;
}

FactorialIterator FactorialIterator::operator++(int)
{
  FactorialIterator tmp(*this);
  ++(*this);
  return tmp;
}

FactorialIterator &FactorialIterator::operator--()
{
  if (currentIndex_ == 1) {
    throw std::logic_error("Minimum factorial operand must be \'1'\'");
  }
  value_ /= currentIndex_--;
  return *this;
}

FactorialIterator FactorialIterator::operator--(int)
{
  FactorialIterator tmp(*this);
  --(*this);
  return tmp;
}

FactorialIterator::value_type FactorialIterator::operator*() const
{
  return value_;
}

bool FactorialIterator::operator==(const FactorialIterator &rhs) const
{
  return (currentIndex_ == rhs.currentIndex_);
}

bool FactorialIterator::operator!=(const FactorialIterator &rhs) const
{
  return !(*this == rhs);
}

Factorial::Factorial() :
  Factorial(10) {}

Factorial::Factorial(const unsigned int size) :
  end_(size + 1) {}

Factorial::iterator Factorial::end() const
{
  return end_;
}

Factorial::iterator Factorial::begin() const
{
  return Factorial::iterator();
}

std::reverse_iterator<Factorial::iterator> Factorial::rbegin() const
{
  return std::reverse_iterator<iterator>(begin());
}

std::reverse_iterator<Factorial::iterator> Factorial::rend() const
{
  return std::reverse_iterator<iterator>(end());
}
