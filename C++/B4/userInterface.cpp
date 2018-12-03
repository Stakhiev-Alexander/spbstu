#include "userInterface.hpp"

#include <iostream>
#include <algorithm>
#include <sstream>

std::istream &operator>>(std::istream &is, phoneBook::contactType &contact)
{
  std::string tmp, num;
  std::getline(std::cin, tmp);
  num = tmp.substr(0, tmp.find(' '));
  for (char c : num) {
    if (!std::isdigit(c)) {
      is.setstate(std::istream::failbit);
      std::cout << "<INVALID COMMAND>\n";
      return is;
    }
  }
  contact.first = num;
  tmp.erase(0, num.size() + 1);
  if (tmp.front() != '\"' || tmp.back() != '\"') {
    is.setstate(std::istream::failbit);
    std::cout << "<INVALID COMMAND>\n";
    return is;
  }
  tmp.pop_back();
  tmp.erase(0, 1);
  tmp.erase(std::remove(tmp.begin(), tmp.end(), '\\'), tmp.end());
  contact.second = tmp;

  return is;
}

UserInterface::UserInterface() : book()
{
  marks["current"] = book.end();
}

void UserInterface::launchInterface()
{
  std::string cmd;
  while (std::cin >> cmd >> std::ws) {
    if (cmd == "add") {
      phoneBook::contactType contact;
      std::cin >> contact;
      if (!std::cin.fail()) {
        book.addContact(contact);
        if (marks["current"] == book.end()) {
          marks["current"] = book.begin();
        }
      }
    } else if (cmd == "store") {
      std::string mark, newMark;
      std::cin >> mark >> newMark;
      if (markExists(mark)) {
        marks[newMark] = marks[mark];
      }
    } else if (cmd == "insert") {
      std::string pos, mark;
      phoneBook::contactType contact;
      std::cin >> pos >> mark >> std::ws >> contact;
      if (markExists(mark) && !std::cin.fail()) {
        if (book.size() == 0) {
          book.addContact(contact);
          marks["current"] = book.begin();
          continue;
        }
        if (pos == "before") {
          book.addBefore(marks[mark], contact);
        } else if (pos == "after") {
          book.addAfter(marks[mark], contact);
        } else {
          std::cout << "<INVALID COMMAND>" << '\n';
        }
      }
    } else if (cmd == "delete") {
      if (book.size() != 0) {
        std::string mark;
        std::cin >> mark;
        auto position = marks.find(mark);
        auto oldMark = position->second;
        position->second = book.deleteContact(position->second);
        if (position->second == book.end()) {
          position->second--;
        }
        for (auto it = marks.begin(); it != marks.end(); ++it) {
          if (it->second == oldMark) {
            it->second = position->second;
          }
        }
      }
    } else if (cmd == "show") {
      std::string mark;
      std::cin >> mark;
      auto it = marks.find(mark);
      if (it != marks.end()) {
        if (it->second != book.end()) {
          std::cout << marks[mark]->first << ' ' << marks[mark]->second << '\n';
        } else {
          std::cout << "<EMPTY>" << '\n';
        }
      } else {
        std::cout << "<INVALID BOOKMARK>" << '\n';
      }
    } else if (cmd == "move") {
      std::string mark, steps;
      std::cin >> mark >> steps;
      if (markExists(mark)) {
        bool allDigits = true;
        for (char c : steps) {
          if (!isdigit(c) && c != '-' && c != '+') {
            allDigits = false;
            break;
          }
        }
        if (allDigits) {
          int iSteps = std::stoi(steps);
          for (int i = 0; i < std::abs(iSteps); i++) {
            if (iSteps > 0 && marks[mark] != std::prev(book.end())) {
              marks[mark]++;
            } else if (marks[mark] != book.begin()) {
              marks[mark]--;
            }
          }
        } else if (steps == "first") {
          marks[mark] = book.begin();
        } else if (steps == "last") {
          marks[mark] = std::prev(book.end());
        } else {
          std::cout << "<INVALID STEP>" << '\n';
        }
      }
    } else {
      std::cout << "<INVALID COMMAND>" << '\n';
    }
    std::cin.clear();
  }
}

bool UserInterface::markExists(std::string mark)
{
  if (marks.find(mark) != marks.end()) {
    return true;
  } else {
    std::cout << "<INVALID BOOKMARK>" << '\n';
    return false;
  }
}
