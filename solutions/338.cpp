#include <algorithm>
#include <vector>

class Solution {
 public:
  std::vector<int> countBits(int n) {
    std::vector<int> result(static_cast<size_t>(n + 1));

    for (size_t shift = 1; (1 << (shift - 1)) < result.size(); ++shift) {
      size_t start = (1 << (shift - 1));
      size_t end = std::min<size_t>(1 << shift, result.size());

      for (size_t index = start; index < end; ++index) {
        result[index] = 1 + result[index - start];
      }
    }

    return result;
  }
};
