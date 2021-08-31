#include <cmath>
#include <string>
#include <vector>

class Solution {
  void letterCasePermutationRecursive(std::string &s,
                                      std::vector<std::string> &result,
                                      size_t pos) {
    if (pos == s.size()) {
      result.push_back(s);
      return;
    }

    letterCasePermutationRecursive(s, result, pos + 1);
    if (isalpha(s[pos])) {
      s[pos] ^= std::abs('A' - 'a');  // toggle case
      letterCasePermutationRecursive(s, result, pos + 1);
    }
  }

 public:
  std::vector<std::string> letterCasePermutation(std::string s) {
    std::vector<std::string> result;
    letterCasePermutationRecursive(s, result, 0);
    return result;
  }
};
