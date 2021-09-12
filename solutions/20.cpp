#include <cmath>
#include <stack>
#include <string>

class Solution {
  static bool is_opening(char c) { return c == '(' or c == '{' or c == '['; }
  static bool matching(char closing, char opening) {
    // in ascii () have distance 1, {} and [] have distance 2
    return std::abs(closing - opening) <= 2;
  }

 public:
  bool isValid(std::string s) {
    std::stack<char> st;
    for (auto c : s) {
      if (is_opening(c)) {
        st.push(c);
      } else if (st.empty() or not matching(c, st.top())) {
        return false;
      } else {
        st.pop();
      }
    }
    return st.empty();
  }
};
