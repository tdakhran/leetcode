#include <vector>

class Solution {
 public:
  int numberOfArithmeticSlices(std::vector<int>& A) {
    int count = 0;
    int prev_count = 0;
    for (size_t pos = 2; pos < A.size(); ++pos) {
      if (A[pos] - A[pos - 1] == A[pos - 1] - A[pos - 2]) {
        ++prev_count;
      } else {
        prev_count = 0;
      }
      count += prev_count;
    }
    return count;
  }
};
