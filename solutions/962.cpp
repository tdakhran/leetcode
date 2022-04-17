#include <stack>
#include <vector>

class Solution {
 public:
  size_t maxWidthRamp(std::vector<int>& nums) {
    std::stack<size_t> st;

    for (size_t pos = 0; pos < nums.size(); ++pos) {
      if (auto n = nums[pos]; st.empty() or nums[st.top()] > n) {
        st.push(pos);
      }
    }

    size_t result = 0;
    for (size_t pos = nums.size(); pos > 0 and not st.empty(); --pos) {
      while (not st.empty() and nums[pos - 1] >= nums[st.top()]) {
        result = std::max(result, pos - 1 - st.top());
        st.pop();
      }
    }
    return result;
  }
};
