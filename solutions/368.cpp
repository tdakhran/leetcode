#include <algorithm>
#include <vector>

class Solution {
 public:
  std::vector<int> largestDivisibleSubset(std::vector<int>& nums) {
    std::sort(begin(nums), end(nums), std::greater<int>());

    std::vector<std::vector<int>> dp(nums.size());

    std::function<size_t(size_t)> dfs = [&dfs, &nums, &dp](size_t id) {
      if (not dp[id].empty()) {
        return dp[id].size();
      }
      auto best_id = id;

      for (size_t edge_id = id + 1; edge_id < nums.size(); ++edge_id) {
        if (nums[id] % nums[edge_id]) {
          continue;
        }
        dfs(edge_id);
        if (dp[edge_id].size() > dp[best_id].size()) {
          best_id = edge_id;
        }
      }
      dp[id] = dp[best_id];
      dp[id].push_back(nums[id]);
      return dp[id].size();
    };

    size_t best_id = 0;
    for (size_t id = 0; id < nums.size(); ++id) {
      if (auto size = dfs(id); size > dp[best_id].size()) {
        best_id = id;
      }
    }

    return dp[best_id];
  }
};
