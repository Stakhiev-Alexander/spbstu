#include "phoneBook.hpp"

#include <iostream>
#include <map>

phoneBook::phoneBook() : contacts()
{
  current = contacts.end();
}

void phoneBook::show()
{
  if (current != contacts.end()) {
    std::cout << current->first << ' ' << current->second << '\n';
  }
}

void phoneBook::goForward()
{
  if (std::next(current) != contacts.end()) {
    current++;
  }
}

void phoneBook::goBack()
{
  if (current != contacts.begin()) {
    current--;
  }
}

void phoneBook::addBefore(std::list <contactType>::iterator pos, phoneBook::contactType contact)
{
  contacts.insert(pos, contact);
}

void phoneBook::addAfter(std::list <contactType>::iterator pos, phoneBook::contactType contact)
{
  contacts.insert(std::next(pos), contact);
}

void phoneBook::replace(phoneBook::contactType contact)
{
  if (current != contacts.end()) {
    current->first = contact.first;
    current->second = contact.second;
  }
}

void phoneBook::addContact(phoneBook::contactType contact)
{
  contacts.push_back(contact);
}

void phoneBook::changePosByNSteps(int steps)
{
  if (steps > 0) {
    while (current != std::prev(contacts.end()) || steps != 0) {
      current++;
      steps--;
    }
  } else {
    while (current != contacts.begin() || steps != 0) {
      current--;
      steps--;
    }
  }
}

std::list <phoneBook::contactType>::iterator phoneBook::deleteContact(std::list <contactType>::iterator pos)
{
  return contacts.erase(pos);
}

std::list <phoneBook::contactType>::iterator phoneBook::begin()
{
  return contacts.begin();
}

std::list <phoneBook::contactType>::iterator phoneBook::end()
{
  return contacts.end();
}

unsigned long long int phoneBook::size()
{
  return contacts.size();
}
