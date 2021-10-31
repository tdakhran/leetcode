#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
    std::vector<std::vector<int>> result = {{}};
    for (auto n : nums) {
      auto current_size = result.size();
      for (size_t pos = 0; pos < current_size; ++pos) {
        auto v = result[pos];
        v.push_back(n);
        result.push_back(v);
      }
    }
    return result;
  }
};
