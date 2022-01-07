#include <functional>
#include <string>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<std::string>> partition(std::string s) {
    std::vector<std::vector<std::string>> result;
    std::vector<std::string> current;

    auto is_palindrome = [](const std::string &str) {
      size_t lo = 0;
      size_t hi = str.size();
      while (lo < hi) {
        if (str[lo++] != str[--hi]) {
          return false;
        }
      }
      return true;
    };

    std::function<void(size_t)> backtrack = [&](size_t start) {
      if (start == s.size()) {
        result.push_back(current);
      }
      std::string str;
      for (size_t pos = start; pos < s.size(); ++pos) {
        str.push_back(s[pos]);
        if (is_palindrome(str)) {
          current.push_back(str);
          backtrack(pos + 1);
          current.pop_back();
        }
      }
    };
    backtrack(0);

    return result;
  }
};
