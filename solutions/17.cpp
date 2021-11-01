#include <functional>
#include <string>
#include <vector>

class Solution {
  static inline constexpr std::array<const char *, 10> Letters = {
      "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

 public:
  std::vector<std::string> letterCombinations(std::string digits) {
    std::vector<std::string> result;
    std::string current;

    std::function<void(size_t)> backtrack = [&backtrack, &result, &current,
                                             &digits](size_t start_pos) {
      if (start_pos == digits.size()) {
        result.push_back(current);
        return;
      }
      for (auto letter :
           std::string(Letters[static_cast<size_t>(digits[start_pos] - '0')])) {
        current.push_back(letter);
        backtrack(start_pos + 1);
        current.pop_back();
      }
    };

    if (not digits.empty()) {
      backtrack(0);
    }
    return result;
  }
};
