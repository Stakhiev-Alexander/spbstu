#ifndef PARSER_HPP
#define PARSER_HPP

class Parser
{
public:
  Parser();

  bool getCharacter();

  void setCharacter();
  void setSyntax();
  void setComma();
  void setDash();
  void setSpace();

private:
  bool character_;
  bool syntax_;
  bool space_;
  bool comma_;
};

#endif
