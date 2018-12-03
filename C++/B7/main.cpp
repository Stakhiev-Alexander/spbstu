#include <iterator>
#include <iostream>
#include <algorithm>

#include "sequencestatistics.hpp"

int main()
{
  SequenceStatistics seqStatistics = std::for_each(std::istream_iterator<int>(std::cin), std::istream_iterator<int>(), SequenceStatistics());

  if(!std::cin.eof())
  {
    std::cerr << "Error: incorrect input";
    return 1;
  }
  else
  {
    seqStatistics.printSeqStatistics(std::cout);
    return 0;
  }
}
