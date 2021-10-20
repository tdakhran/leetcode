#include <algorithm>
#include <string>

class Solution {
 public:
  std::string reverseWords(std::string s) {
    std::string result;

    for (size_t start_pos = 0; start_pos < s.size();) {
      auto next_space_pos = std::min(s.find(' ', start_pos), s.size());

      if (next_space_pos > start_pos and not result.empty()) {
        result.push_back(' ');
      }

      for (auto p = next_space_pos; p > start_pos; --p) {
        result.push_back(s[p - 1]);
      }
      start_pos = next_space_pos + 1;
    }

    std::reverse(begin(result), end(result));
    return result;
  }
};
