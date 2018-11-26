#include <vector>
#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include "impl.hpp"
#include "accessTypes.hpp"

void fillRandom(double * array, int size)
{
  for (int i = 0; i < size; i++) {
    array[i] = ((rand() % 20 - 10) * 0.1);
  }
}

void fourthTask(int argc, char *argv[])
{
  if (argc != 4) {
    throw std::invalid_argument("TASK 4: Wrong number of arguments");
  }

  auto comparisonType = detail::getComparisonType<double>(argv[2]);
  std::vector<double> vector(std::stoi(argv[3]));
  srand(time(0));
  fillRandom(&vector[0], std::stoi(argv[3]));

  detail::print(vector);
  detail::sort(vector, access::AccessByIterator<std::vector<double>>(), comparisonType);
  detail::print(vector);
}
