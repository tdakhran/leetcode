#include <stack>
#include <string>

class Solution {
 public:
  int longestValidParentheses(std::string s) {
    std::stack<int> st;
    st.push(-1);
    int longest = 0;
    for (int pos = 0; pos < static_cast<int>(s.size()); ++pos) {
      if (s[static_cast<size_t>(pos)] == '(') {
        st.push(pos);
      } else {
        if (st.size()) {
          st.pop();
        }

        if (not st.empty()) {
          longest = std::max(longest, pos - st.top());
        } else {
          st.push(pos);
        }
      }
    }
    return longest;
  }
};
