#include <vector>

class Solution {
 public:
  int sumOddLengthSubarrays(std::vector<int>& arr) {
    int total_sum = 0;
    for (auto it = begin(arr); it != end(arr); ++it) {
      int current_sum = 0;
      for (auto jt = it; jt != end(arr); ++jt) {
        current_sum += *jt;
        if (std::distance(it, jt) % 2 == 0) {
          total_sum += current_sum;
        }
      }
    }
    return total_sum;
  }
};
