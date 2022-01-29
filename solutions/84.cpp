#include <stack>
#include <vector>

class Solution {
 public:
  int largestRectangleArea(std::vector<int>& heights) {
    int result = 0;

    std::stack<size_t> st;

    for (size_t pos = 0; pos < heights.size(); ++pos) {
      int height = heights[pos];
      while (st.size() and heights[st.top()] > height) {
        size_t top_index = st.top();
        st.pop();

        size_t length = st.empty() ? pos : (pos - st.top() - 1);
        int area = heights[top_index] * static_cast<int>(length);
        result = std::max(result, area);
      }
      st.push(pos);
    }

    while (not st.empty()) {
      size_t top_index = st.top();
      st.pop();

      size_t length =
          st.empty() ? heights.size() : (heights.size() - st.top() - 1);
      int area = heights[top_index] * static_cast<int>(length);
      result = std::max(result, area);
    }
    return result;
  }
};
