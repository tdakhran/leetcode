#include <cmath>
#include <vector>

struct Iterator {
  Iterator(int *ptr_in, const int *end_in, const int inc_in)
      : ptr(ptr_in), end(end_in), inc(inc_in) {}

  operator bool() const { return ptr != end; }
  void operator++() { ptr += inc; }
  int operator*() const { return *ptr; }

 private:
  int *ptr{nullptr};
  const int *end;
  const int inc;
};

class Solution {
 public:
  std::vector<int> sortedSquares(std::vector<int> &nums) {
    int64_t first_positive =
        distance(begin(nums), lower_bound(begin(nums), end(nums), 0));
    Iterator positive =
        Iterator(&nums.front() + first_positive, &nums.back() + 1, 1);
    Iterator negative =
        Iterator(&nums.front() + first_positive - 1, &nums.front() - 1, -1);

    std::vector<int> result;
    result.reserve(nums.size());

    while (negative and positive) {
      auto &it = abs(*negative) < abs(*positive) ? negative : positive;
      result.push_back(*it * *it);
      ++it;
    }
    while (negative) {
      result.push_back(*negative * *negative);
      ++negative;
    }
    while (positive) {
      result.push_back(*positive * *positive);
      ++positive;
    }
    return result;
  }
};
