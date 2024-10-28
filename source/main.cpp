
#include <array>
#include <vector>
#include <iostream>
#include <iterator>

#include "collection.hpp"

int main()
{
  std::array<int, 10> data{2, 4, 5, 6, 3, 2, 4, 45, 3, 2};

  collection::Collection<int> collection{data};

  auto print = [](auto&& item) {
    std::cout << item << std::endl;
  };

  int value = collection
                  .each(print)
                  .each([](auto&& item) {
                    if (item % 2 == 0)
                    {
                      item *= 2;
                    }
                  })
                  .each(print)
                  .sort()
                  .each(print)
                  .sort([](auto&& a, auto&& b) {
                    return a > b;
                  })
                  .each(print)
                  .get(0);

  std::cout << value << std::endl;
  std::cout << "Size: " << collection.size() << std::endl;
  std::cout << collection.pluck(0) << std::endl;
  std::cout << "Size: " << collection.size() << std::endl;

  std::vector<int> vector{};

  std::copy(data.begin(), data.end(), std::back_insert_iterator{vector});

  std::cout << "Size: " << vector.size() << std::endl;
  for (auto&& item : vector)
  {
    std::cout << item << std::endl;
  }

  for (auto&& item : vector)
  {
    if (item % 2 == 0)
    {
      item *= 2;
    }
  }

  for (auto&& item : vector)
  {
    std::cout << item << std::endl;
  }

  std::sort(vector.begin(), vector.end());

  for (auto&& item : vector)
  {
    std::cout << item << std::endl;
  }

  std::sort(vector.begin(), vector.end(), [](auto&& a, auto&& b) {
    return a > b;
  });

  for (auto&& item : vector)
  {
    std::cout << item << std::endl;
  }

  std::cout << vector.at(0) << std::endl;

  std::cout << "Size: " << vector.size() << std::endl;
  std::cout << vector.at(0) << std::endl;
  vector.erase(vector.begin());
  std::cout << "Size: " << vector.size() << std::endl;
}
