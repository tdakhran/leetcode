#include <stack>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  std::vector<int> nextGreaterElement(std::vector<int>& nums1,
                                      std::vector<int>& nums2) {
    std::unordered_map<int, int> next;
    std::stack<int> st;

    for (auto it = nums2.crbegin(); it != nums2.crend(); ++it) {
      while (not st.empty() and st.top() < *it) {
        st.pop();
      }
      next[*it] = (not st.empty()) ? st.top() : -1;
      st.push(*it);
    }

    std::vector<int> result;
    result.reserve(nums1.size());
    for (auto n : nums1) {
      auto it = next.find(n);
      result.push_back(it != end(next) ? it->second : -1);
    }
    return result;
  }
};
