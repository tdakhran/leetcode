#include <functional>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> permute(std::vector<int>& nums) {
    std::vector<std::vector<int>> result;
    std::vector<int> cur;

    std::function<void(const size_t)> generate = [&generate, &nums, &result,
                                                  &cur](const size_t start) {
      if (cur.size() == nums.size()) {
        result.push_back(cur);
        return;
      }
      for (size_t pos = start; pos < nums.size(); ++pos) {
        std::swap(nums[start], nums[pos]);
        cur.push_back(nums[start]);
        generate(start + 1);
        cur.pop_back();
        std::swap(nums[start], nums[pos]);
      }
    };

    generate(0);

    return result;
  }
};
