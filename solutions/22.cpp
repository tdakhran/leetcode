#include <functional>
#include <vector>

class Solution {
 public:
  std::vector<std::string> generateParenthesis(int n) {
    std::vector<std::string> result;
    std::string current;

    std::function<void(int, int)> backtrack = [&backtrack, &result, &current](
                                                  int pairs, int count) {
      if (pairs == 0 and count == 0) {
        result.push_back(current);
        return;
      }
      if (count < 0 or pairs < 0) {
        return;
      }

      for (const auto bracket : {'(', ')'}) {
        current.push_back(bracket);
        backtrack(pairs - (bracket == '('),
                  count + (bracket == '(') - (bracket == ')'));
        current.pop_back();
      }
    };

    backtrack(n, 0);
    return result;
  }
};
