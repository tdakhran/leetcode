#include <algorithm>
#include <functional>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates,
                                                int target) {
    std::sort(begin(candidates), end(candidates));

    std::vector<std::vector<int>> result;
    std::vector<int> current;

    std::function<void(size_t, int)> backtrack = [&backtrack, &result, &current,
                                                  &candidates](size_t start_pos,
                                                               int residual) {
      if (residual == 0) {
        result.push_back(current);
        return;
      }
      if (residual < 0) {
        return;
      }

      for (size_t pos = start_pos; pos < candidates.size(); ++pos) {
        if (auto cand = candidates[pos];
            pos == start_pos or candidates[pos - 1] != cand) {
          current.push_back(candidates[pos]);
          backtrack(pos + 1, residual - candidates[pos]);
          current.pop_back();
        }
      }
    };

    backtrack(0, target);
    return result;
  }
};
