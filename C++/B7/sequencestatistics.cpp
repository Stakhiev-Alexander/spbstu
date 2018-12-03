#include "sequencestatistics.hpp"

#include <iomanip>

void SequenceStatistics::operator() (long int number)
{
  if(number > 0) {
    positiveNumbCounter_++;
  } else if(number < 0) {
    negativeNumbCounter_ ++;
  }

  if(number % 2 == 0) {
    evenSum_ += number;
  } else {
    oddSum_ += number;
  }

  if(elemCounter_ == 0) {
    firstElem_ = number;
    maxNumber_ = number;
    minNumber_ = maxNumber_;
  }

  maxNumber_ = std::max(maxNumber_, number);
  minNumber_ = std::min(minNumber_, number);
  lastElem_ = number;
  elemCounter_ ++;
}

void SequenceStatistics::printSeqStatistics(std::ostream &out)
{
  if(elemCounter_ == 0) {
    out << "No Data" << std::endl;
    return;
  }

  out << "Max: " << maxNumber_ << std::endl
      << "Min: " << minNumber_ << std::endl
      << "Mean: " << ((evenSum_ + oddSum_) / elemCounter_) <<  std::endl
      << "Positive: " << positiveNumbCounter_ <<  std::endl
      << "Negative: " << negativeNumbCounter_ <<  std::endl
      << "Odd Sum: " << oddSum_ <<  std::endl
      << "Even Sum: " << evenSum_ <<  std::endl
      << "First/Last Equal: " << (firstElem_ == lastElem_ ? "yes" : "no") <<  std::endl;
}
