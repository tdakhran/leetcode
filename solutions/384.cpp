#include <cstdlib>
#include <vector>

class Solution {
  std::vector<int> nums_;

 public:
  Solution(std::vector<int>& nums) : nums_(std::move(nums)) {}

  std::vector<int> reset() { return nums_; }

  std::vector<int> shuffle() {
    auto result = nums_;
    for (size_t pos = 0; pos < result.size(); ++pos) {
      std::swap(result[pos],
                result[static_cast<size_t>(rand()) % result.size()]);
    }
    return result;
  }
};
