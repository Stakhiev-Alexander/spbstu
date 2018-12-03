#ifndef SEQUENCESTATISTICS_HPP
#define SEQUENCESTATISTICS_HPP

#include <iostream>

class SequenceStatistics
{
public:
  void operator() (long int number);
  void printSeqStatistics(std::ostream &out);

private:
  long int maxNumber_;
  long int minNumber_;
  long int positiveNumbCounter_;
  long int negativeNumbCounter_;
  long long int oddSum_;
  long long int evenSum_;
  long int firstElem_;
  long int lastElem_;
  long int elemCounter_;
};


#endif
