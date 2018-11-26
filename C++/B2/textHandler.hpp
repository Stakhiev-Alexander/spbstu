#ifndef TEXT_HANDLER_HPP
#define TEXT_HANDLER_HPP

#include <vector>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <locale>

#include "parser.hpp"

const size_t maxLengthOfWord = 20;
const size_t maxLengthOfNumber = 20;

template<typename IteratorType>
class TextHandler
{
public:
  explicit TextHandler(size_t lineWidth);
  void handle(IteratorType begin, IteratorType end);

private:
  Parser currentState_;
  const size_t lineWidth_;
  std::vector<char> string_;
  std::vector<char> character_;
  IteratorType iterator_;
  IteratorType end_;

  void newCharacter();
  bool readCharacter();
  bool readNumber();
  bool readSyntax();
  bool readSpace();
};

template <typename IteratorType>
TextHandler<IteratorType>::TextHandler(size_t lineWidth) :
  currentState_(),
  lineWidth_(lineWidth),
  string_(),
  character_(),
  iterator_(),
  end_()
{}

template<typename IteratorType>
void TextHandler<IteratorType>::handle(IteratorType begin, IteratorType end)
{
  if (begin == end) {
    return;
  }
  iterator_ = begin;
  end_ = end;
  iterator_ --;

  while (iterator_ != end_) {
    iterator_ ++;
    if (!(readCharacter() || readNumber() || readSpace() || readSyntax())) {
      return;
    }
  }

  newCharacter();
  if (!string_.empty()) {
    std::copy(string_.begin(), string_.end() - 1, std::ostream_iterator<char>(std::cout));
    std::cout << std::endl;
  }
}

template<typename IteratorType>
void TextHandler<IteratorType>::newCharacter()
{
  size_t sizeC = character_.size();
  size_t sizeStr = string_.size();

  if (sizeStr + sizeC < lineWidth_) {
    string_.insert(string_.end(), character_.begin(), character_.end());
    if (!string_.empty()) {
      string_.push_back(' ');
    }
  } else if (sizeStr + sizeC == lineWidth_) {
    std::copy(string_.begin(), string_.end(), std::ostream_iterator<char>(std::cout));
    std::copy(character_.begin(), character_.end(), std::ostream_iterator<char>(std::cout));
    std::cout << std::endl;
    string_.clear();
  } else {
    std::copy(string_.begin(), string_.end() - 1, std::ostream_iterator<char>(std::cout));
    std::cout << std::endl;
    string_.clear();
    std::vector<char>::iterator begin = character_.begin();
    string_.insert(string_.end(), begin, character_.end());
    string_.push_back(' ');
  }

  character_.clear();
  currentState_.setCharacter();
}

template<typename IteratorType>
bool TextHandler<IteratorType>::readCharacter()
{
  std::locale cloc("C");
  if (std::isalpha(*iterator_, cloc)) {
    if (currentState_.getCharacter()) {
      newCharacter();
    }
  } else {
    return false;
  }

  while (iterator_ != end_) {
    if (std::isalpha(*iterator_, cloc)) {
      character_.push_back(*iterator_);
    } else if (*iterator_ == '-') {
      character_.push_back(*iterator_);
      break;
    } else {
      iterator_--;
      break;
    }

    iterator_++;
  }

  if (character_.size() > maxLengthOfWord) {
    throw std::invalid_argument("Max length of the word is 20 characters");
  }

  return true;
}

template<typename IteratorType>
bool TextHandler<IteratorType>::readNumber()
{

  std::locale cloc("C");
  if (isdigit(*iterator_, cloc) || *iterator_ == '+') {
    newCharacter();
  } else if (*iterator_ == '-' && isdigit(*(iterator_+1), cloc)) {
    ++iterator_;
    newCharacter();
    character_.push_back('-');
  } else {
    return false;
  }

  char point = std::use_facet< std::numpunct<char> >(std::cin.getloc()).decimal_point();

  while (iterator_ != end_) {
    if (isdigit(*iterator_, cloc) || *iterator_ == point || *iterator_ == '+') {
      character_.push_back(*iterator_);
    } else {
      iterator_--;
      break;
    }
    iterator_++;
  }

  if (character_.size() > maxLengthOfNumber) {
    throw std::invalid_argument("Max length of the number is 20 characters");
  }

  return true;
}

template<typename IteratorType>
bool TextHandler<IteratorType>::readSyntax()
{
  if (*iterator_ == '-') {
    currentState_.setDash();

    if (*(++iterator_) == '-' && *(++iterator_) == '-') {
      character_.push_back(' ');
      character_.push_back('-');
      character_.push_back('-');
      character_.push_back('-');
    } else {
      throw std::invalid_argument("Unknown character");
    }
  } else if (ispunct(*iterator_)) {
    if (*iterator_ == ',') {
      currentState_.setComma();
    } else {
      currentState_.setSyntax();
    }

    character_.push_back(*iterator_);
  } else {
    return false;
  }

  return true;
}

template<typename IteratorType>
bool TextHandler<IteratorType>::readSpace()
{
  if (isspace(*iterator_)) {
    currentState_.setSpace();
    while (iterator_ != end_) {
      if (!isspace(*iterator_)) {
        iterator_--;
        break;
      }
      iterator_++;
    }
  } else {
    return false;
  }

  return true;
}

#endif
