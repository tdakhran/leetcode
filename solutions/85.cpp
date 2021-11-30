#include <stack>
#include <vector>

class Solution {
 public:
  int maximalRectangle(std::vector<std::vector<char>>& matrix) {
    if (matrix.empty() or matrix.front().empty()) {
      return 0;
    }
    std::vector<size_t> cols(matrix.front().size());

    size_t result = 0;
    for (const auto& row : matrix) {
      std::stack<size_t> st;
      for (size_t col = 0; col < row.size(); ++col) {
        cols[col] = (row[col] == '1') * (cols[col] + 1);
        while (not st.empty() and cols[st.top()] > cols[col]) {
          size_t col_id = st.top();
          st.pop();
          size_t length = st.empty() ? col : (col - st.top() - 1);
          result = std::max(result, cols[col_id] * length);
        }
        st.push(col);
      }
      while (st.size()) {
        size_t col_id = st.top();
        st.pop();
        size_t length = st.empty() ? cols.size() : (cols.size() - st.top() - 1);
        result = std::max(result, cols[col_id] * length);
      }
    }

    return static_cast<int>(result);
  }
};
