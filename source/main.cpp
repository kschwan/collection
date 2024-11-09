
#include <array>
#include <vector>
#include <iostream>
#include <iterator>
#include <ranges>

#include "collection.hpp"

int main()
{
  std::array<int, 10> data{2, 4, 5, 6, 3, 2, 4, 45, 3, 2};

  collection::Collection<int> collection{data};

  auto print = [](auto&& item) {
    std::cout << item << std::endl;
  };

  // With method chaining
  {
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
    // The below pluck() is a problem regarding exception safety if
    // decltype(collection)::value_type's ctor throws! This is the
    // reason why vector::pop_front() doesn't return the popped value.
    std::cout << collection.pluck(0) << std::endl;
    std::cout << "Size: " << collection.size() << std::endl;
  }

  // With regular <algorithm>s
  {
    std::vector<int> vector{data.begin(), data.end()};
    std::for_each(vector.begin(), vector.end(), print);
    std::for_each(vector.begin(), vector.end(), [](auto&& item) {
      if (item % 2 == 0)
      {
        item *= 2;
      }
    });
    std::for_each(vector.begin(), vector.end(), print);
    std::sort(vector.begin(), vector.end(), std::greater<int>{});
    std::for_each(vector.begin(), vector.end(), print);
    int value = vector[0];

    std::cout << value << std::endl;
    std::cout << "Size: " << vector.size() << std::endl;
    std::cout << vector.at(0) << std::endl; // or vector.front()
    vector.erase(vector.begin());           // or vector.pop_front()?
    std::cout << "Size: " << vector.size() << std::endl;
  }

  // With <ranges>
  {
    namespace rng = std::ranges;
    std::vector<int> vector{data.begin(), data.end()};
    // With newer GCC, vector can also be constructed like so:
    //   - std::vector<int> vector{std::from_range, data}; or
    //   - auto vector = std::ranges::to<std::vector>(data);
    rng::for_each(vector, print);
    rng::for_each(vector, [](auto&& item) {
      if (item % 2 == 0)
      {
        item *= 2;
      }
    });
    rng::for_each(vector, print);
    rng::sort(vector, std::greater<int>{});
    rng::for_each(vector, print);
    int value = vector[0];

    std::cout << value << std::endl;
    std::cout << "Size: " << vector.size() << std::endl;
    std::cout << vector.at(0) << std::endl; // or vector.front()
    vector.erase(vector.begin());           // or vector.pop_front()?
    std::cout << "Size: " << vector.size() << std::endl;
  }
}
