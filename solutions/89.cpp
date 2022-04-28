#include <vector>

class Solution {
 public:
  std::vector<int> grayCode(int n) {
    std::vector<int> result = {0};
    for (size_t i = 0; i < static_cast<size_t>(n); ++i) {
      for (size_t j = result.size(); j > 0; --j) {
        result.push_back((1 << i) + result[j - 1]);
      }
    }
    return result;
  }
};
