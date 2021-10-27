#include <algorithm>
#include <string>

class Solution {
 public:
  std::string minRemoveToMakeValid(std::string s) {
    std::string result;

    int count = 0;
    for (auto c : s) {
      count += (c == '(') - (c == ')');
      if (count >= 0) {
        result.push_back(c);
      }
      count = std::max(count, 0);
    }

    std::reverse(begin(result), end(result));
    std::string rev_result;

    for (auto c : result) {
      if (c == '(' and count-- > 0) {
        continue;
      }
      rev_result.push_back(c);
    }

    std::reverse(begin(rev_result), end(rev_result));
    return rev_result;
  }
};
