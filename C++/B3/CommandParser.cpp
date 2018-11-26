#include "CommandParser.hpp"

void detail::commandParser(const std::string &str)
{
  unsigned int i = 0;
  QueueWithPriority<QueueElement<std::string>> queueWithPriority;

  while (i < str.length()) {
    if (str.substr(i, 4) == "add ") {
      addCommand(str, queueWithPriority, i);
    } else if (str.substr(i, 3) == "get" && (str[i + 3] == '\n' || str[i + 3] == '\r')) {
      getCommand(queueWithPriority, i);
    } else if (str.substr(i, 10) == "accelerate" && (str[i + 10] == '\n' || str[i + 10] == '\r')) {
      accelerateCommand(queueWithPriority, i);
    } else {
      invalidCommand(str, i);
    }
  }
}

void detail::addCommand(const std::string &str, QueueWithPriority<QueueElement<std::string>> &queueWithPriority, unsigned int &i)
{
  i += 4;
  QueueElement<std::string> queueElement;
  queueElement.name = "";
  queueElement.priority = ElementPriority::LOW;
  if (str.substr(i, 4) == "low ") {
    i += 4;
    queueElement.priority = ElementPriority::LOW;
  } else if (str.substr(i, 7) == "normal ") {
    i += 7;
    queueElement.priority = ElementPriority::NORMAL;
  } else if (str.substr(i, 5) == "high ") {
    i += 5;
    queueElement.priority = ElementPriority::HIGH;
  } else {
    invalidCommand(str, i);
    return;
  }
  while (str[i] != '\n' && str[i] != '\r') {
    queueElement.name += str[i];
    i++;
  }
  if (!queueElement.name.empty()) {
    queueWithPriority.putElementToQueue(queueElement);
    i++;
  } else {
    invalidCommand(str, i);
  }
}

void detail::getCommand(QueueWithPriority<QueueElement<std::string>> &queueWithPriority, unsigned int &i)
{
  queueWithPriority.getElementFromQueue();
  i += 4;
}

void detail::accelerateCommand(QueueWithPriority<QueueElement<std::string>> &queueWithPriority, unsigned int &i)
{
  queueWithPriority.accelerate();
  i += 11;
}

void detail::invalidCommand(const std::string &str, unsigned int &i)
{
  std::cout << "<INVALID COMMAND>" << std::endl;
  while (str[i] != '\n' && str[i] != '\r') {
    i++;
  }
  i++;
}
