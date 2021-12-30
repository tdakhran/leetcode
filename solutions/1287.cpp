#include <vector>

class Solution {
 public:
  int findSpecialInteger(std::vector<int>& arr) {
    int candidate = -1;
    int count = 0;
    int result = 0;
    int max_count = 0;

    for (auto e : arr) {
      if (e == candidate) {
        ++count;
      } else {
        count = 1;
        candidate = e;
      }
      if (count > max_count) {
        max_count = count;
        result = candidate;
      }
    }
    return result;
  }
};
