#ifndef B3_COMMANDPARSER_HPP
#define B3_COMMANDPARSER_HPP

#include "QueueWithPriority.hpp"

namespace detail
{
  void commandParser(const std::string &str);
  void addCommand(const std::string &str, QueueWithPriority<QueueElement<std::string>> &queueWithPriority, unsigned int &i);
  void getCommand(QueueWithPriority<QueueElement<std::string>> &queueWithPriority, unsigned int &i);
  void accelerateCommand(QueueWithPriority<QueueElement<std::string>> &queueWithPriority, unsigned int &i);
  void invalidCommand(const std::string &str, unsigned int &i);
}

#endif
