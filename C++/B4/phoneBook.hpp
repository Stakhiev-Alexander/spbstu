#ifndef B4_phoneBook_HPP
#define B4_phoneBook_HPP

#include <string>
#include <list>

class phoneBook
{
public:
  typedef std::pair<std::string, std::string> contactType;

  phoneBook();
  void show();
  void goForward();
  void goBack();
  void addBefore(std::list <contactType>::iterator pos, contactType contact);
  void addAfter(std::list <contactType>::iterator pos, contactType contact);
  void replace(contactType contact);
  void addContact(contactType contact);
  void changePosByNSteps(int steps);
  unsigned long long int size();
  std::list <contactType>::iterator deleteContact(std::list <contactType>::iterator pos);
  std::list <contactType>::iterator begin();
  std::list <contactType>::iterator end();

private:
  std::list <contactType> contacts;
  std::list <contactType>::iterator current;
};

#endif
