#include <string>

class Solution {
 public:
  bool backspaceCompare(std::string s, std::string t) {
    auto typed = [](const std::string &str) {
      std::string result;
      for (auto c : str) {
        if (c == '#') {
          if (not result.empty()) {
            result.pop_back();
          }
        } else {
          result.push_back(c);
        }
      }
      return result;
    };
    return typed(s) == typed(t);
  }
};
