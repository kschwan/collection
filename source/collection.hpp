
#ifndef COLLECTION_HPP
#define COLLECTION_HPP

#include <span>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>

namespace collection
{
  template <class T>
  class Collection
  {
    public:
      Collection()
          : data_{}
      {
      }

      Collection(std::span<T> data)
          : Collection{}
      {
        std::copy(data.begin(), data.end(), std::back_insert_iterator(data_));
      }

      Collection(const Collection&)            = delete;
      Collection& operator=(const Collection&) = delete;

      Collection& append(T item)
      {
        data_.push_back(item);

        return *this;
      }

      Collection& append(std::span<T> items)
      {
        for (auto&& item : items)
        {
          data_.push_back(item);
        }

        return *this;
      }

      Collection& each(std::function<void(T&)>&& lambda)
      {
        for (auto&& item : data_)
        {
          lambda(item);
        }

        return *this;
      }

      Collection& sort()
      {
        std::sort(data_.begin(), data_.end());

        return *this;
      }

      Collection& sort(std::function<bool(T, T)>&& lambda)
      {
        std::sort(data_.begin(), data_.end(), lambda);

        return *this;
      }

      Collection& erase(int position)
      {
        data_.erase(data_.begin() + position);

        return *this;
      }

      Collection& erase(int begin, int end)
      {
        data_.erase(data_.begin() + begin, data_.begin() + end);

        return *this;
      }

      Collection& clear()
      {
        data_.clear();

        return *this;
      }

      T get(int position)
      {
        return at(position);
      }

      T pluck(int position)
      {
        T item = at(position);
        data_.erase(data_.begin() + position);

        return item;
      }

      size_t size()
      {
        return data_.size();
      }

    protected:
      T at(int position)
      {
        return data_.at(position);
      }

    private:
      std::vector<T> data_;
  };
} // namespace collection

#endif /* COLLECTION_HPP */
