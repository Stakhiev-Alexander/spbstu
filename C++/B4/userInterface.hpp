#ifndef B4_INTERFACE_HPP
#define B4_INTERFACE_HPP

#include <map>
#include <string>

#include "phoneBook.hpp"

std::istream& operator>>(std::istream& is, phoneBook::contactType &contact);

class UserInterface
{
public:
  UserInterface();
  void launchInterface();
  bool markExists(std::string mark);

private:
  std::map<std::string, std::list<phoneBook::contactType>::iterator> marks;
  phoneBook book;
};

#endif
