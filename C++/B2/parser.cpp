#include "parser.hpp"
#include <stdexcept>

Parser::Parser():
  character_(false),
  syntax_(false),
  space_(true),
  comma_(false)
{}

bool Parser::getCharacter()
{
  return syntax_ || space_ || !character_;
}

void Parser::setCharacter()
{
  character_ = true;
  space_ = false;
  syntax_ = false;
  comma_ = false;
}

void Parser::setSyntax()
{
  if (syntax_) {
    throw std::invalid_argument("Punctuation mark can not be followed by punctuation mark");
  }

  if (!character_) {
    throw std::invalid_argument("Punctuation mark are allowed only after words");
  }

  character_ = false;
  syntax_ = true;
  space_ = true;
}

void Parser::setComma()
{
  Parser::setSyntax();
  comma_ = true;
}

void Parser::setDash()
{
  if (!(comma_ || character_)) {
    throw std::invalid_argument("Punctuation error");
  }
  syntax_ = true;
  character_ = false;
  comma_ = false;
  space_ = true;
}

void Parser::setSpace()
{
  space_ = true;
}
