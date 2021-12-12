#include <stack>
#include <string>
#include <utility>

class Solution {
 public:
  std::string decodeString(std::string s) {
    std::stack<std::pair<int, std::string>> stack;
    stack.push({1, ""});
    for (size_t k = 0; k < s.size(); ++k) {
      int digit = 0;
      while (isdigit(s[k])) {
        digit = digit * 10 + (s[k] - '0');
        ++k;
      }
      if (digit) {
        stack.push({digit, ""});
        continue;
      }
      if (isalpha(s[k])) {
        stack.top().second.push_back(s[k]);
        continue;
      }
      if (s[k] == ']') {
        auto [count, str] = stack.top();
        stack.pop();
        while (count--) {
          stack.top().second += str;
        }
      }
    }
    return stack.top().second;
  }
};
