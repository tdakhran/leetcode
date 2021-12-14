#include <stack>
#include <vector>

class Solution {
 public:
  bool find132pattern(std::vector<int>& nums) {
    if (nums.size() < 3) return false;
    std::stack<int> stack;
    std::vector<int> minimums(nums.size());
    minimums.front() = nums.front();
    for (size_t i = 1; i < nums.size(); i++) {
      minimums[i] = std::min(minimums[i - 1], nums[i]);
    }
    for (size_t j = nums.size(); j > 0; j--) {
      if (nums[j - 1] > minimums[j - 1]) {
        while (!stack.empty() && stack.top() <= minimums[j - 1]) {
          stack.pop();
        }
        if (!stack.empty() && stack.top() < nums[j - 1]) {
          return true;
        }
        stack.push(nums[j - 1]);
      }
    }
    return false;
  }
};
