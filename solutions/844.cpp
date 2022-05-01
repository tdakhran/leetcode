#include <string>

class Solution {
  static inline constexpr char backspace = '#';

 public:
  bool backspaceCompare(std::string s, std::string t) {
    auto typed = [](const std::string &str) {
      std::string result;
      for (auto c : str) {
        if (c != backspace) {
          result.push_back(c);
        } else if (not result.empty()) {
          result.pop_back();
        }
      }
      return result;
    };
    return typed(s) == typed(t);
  }
};
