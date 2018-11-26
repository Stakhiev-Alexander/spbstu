#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iterator>

#include "textHandler.hpp"

const int minWidth = 24;
const int defaultWidth = 40;

int main(int argc, char const *argv[])
{
  try {
    size_t lineWidth = defaultWidth;
    if (argc == 3) {
      if ((strcmp("--line-width", argv[1]) == 0) && (std::atoi(argv[2]) > minWidth)) {
        lineWidth = std::atoi(argv[2]);
      } else {
        std::cerr << "Invalid input arguments";
        return 1;
      }
    } else if (argc == 1) {
      lineWidth = defaultWidth;
    } else {
      std::cerr << "Invalid input arguments";
      return 1;
    }

    TextHandler<std::vector<char>::iterator> textHandler(lineWidth);
    std::vector<char> inputVector;

    std::cin >> std::noskipws;
    std::copy(std::istream_iterator<char>(std::cin), std::istream_iterator<char>(), std::back_inserter(inputVector));

    if (!std::cin.eof() && std::cin.fail()) {
      std::cerr << "Reading input file failed";
      return 1;
    }

    textHandler.handle(inputVector.begin(), inputVector.end());
  }

  catch (std::invalid_argument &ex) {
    std::cerr << ex.what() << '\n';
    return 1;
  }

  return 0;
}
