#include <vector>

class Solution {
 public:
  std::vector<long long> sumOfThree(long long num) {
    if (auto n = (num - 3) / 3; (num - 3) % 3 == 0) {
      return {n, n + 1, n + 2};
    }
    return {};
  }
};
