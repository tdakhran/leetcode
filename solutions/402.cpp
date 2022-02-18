#include <algorithm>
#include <stack>
#include <string>

class Solution {
 public:
  std::string removeKdigits(std::string num, int k) {
    std::stack<char> st;

    // monotonic stack with max k pops
    for (auto c : num) {
      while (k and not st.empty() and c < st.top()) {
        st.pop();
        --k;
      }
      st.push(c);
    }

    // use pops if there are some
    while (k and not st.empty()) {
      st.pop();
      --k;
    }

    std::string result;

    while (not st.empty()) {
      result.push_back(st.top());
      st.pop();
    }

    // remove leading zeros
    while (not result.empty() and result.back() == '0') {
      result.pop_back();
    }

    std::reverse(begin(result), end(result));

    return result.empty() ? "0" : result;
  }
};
