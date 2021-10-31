#include <algorithm>
#include <functional>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates,
                                               int target) {
    std::sort(begin(candidates), end(candidates));

    std::vector<std::vector<int>> result;
    std::vector<int> current;

    std::function<void(std::vector<int>::iterator, int)> backtrack =
        [&backtrack, &candidates, &result, &current](
            std::vector<int>::iterator it, int residual) {
          if (residual == 0) {
            result.push_back(current);
          }
          for (; it != end(candidates) and *it <= residual; ++it) {
            current.push_back(*it);
            backtrack(it, residual - *it);
            current.pop_back();
          }
        };
    backtrack(begin(candidates), target);

    return result;
  }
};
