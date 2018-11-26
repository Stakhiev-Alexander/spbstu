#ifndef B3_QUEUEWITHPRIORITY_HPP
#define B3_QUEUEWITHPRIORITY_HPP

#include <list>
#include <array>
#include <iostream>

enum ElementPriority
{
  LOW,
  NORMAL,
  HIGH
};

template <typename T>
struct QueueElement
{
  T name;
  ElementPriority priority;
};

template <typename T>
class QueueWithPriority
{
public:
  void putElementToQueue(const T & element);
  void getElementFromQueue();
  void accelerate();

private:
  std::list<T> lowPriorityList_;
  std::list<T> normalPriorityList_;
  std::list<T> highPriorityList_;
};

template <typename T>
void QueueWithPriority<T>::putElementToQueue(const T &element)
{
  if (element.priority == LOW) {
    lowPriorityList_.push_back(element);
  } else if (element.priority == NORMAL) {
    normalPriorityList_.push_back(element);
  } else if (element.priority == HIGH) {
    highPriorityList_.push_back(element);
  }
}

template <typename T>
void QueueWithPriority<T>::getElementFromQueue()
{
  if (!highPriorityList_.empty()) {
    std::cout << highPriorityList_.front().name << '\n';
    highPriorityList_.pop_front();
  } else if (!normalPriorityList_.empty()) {
    std::cout << normalPriorityList_.front().name << '\n';
    normalPriorityList_.pop_front();
  } else if (!lowPriorityList_.empty()) {
    std::cout << lowPriorityList_.front().name << '\n';
    lowPriorityList_.pop_front();
  } else {
    std::cout << "<EMPTY>\n";
  }
}

template <typename T>
void QueueWithPriority<T>::accelerate()
{
  highPriorityList_.splice(highPriorityList_.end(), lowPriorityList_);
}

#endif
