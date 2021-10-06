#include <algorithm>
#include <queue>
#include <vector>

class Solution {
 public:
  int coinChange(std::vector<int>& coins, int amount) {
    coins.resize(static_cast<size_t>(std::distance(
        begin(coins),
        std::partition(begin(coins), end(coins),
                       [amount](int coin) { return coin <= amount; }))));
    std::sort(begin(coins), end(coins), std::greater<int>());
    std::vector<int> steps_dp(static_cast<size_t>(amount + 1), 0);
    std::queue<int> bfs_queue;
    bfs_queue.push(amount);

    while (not bfs_queue.empty()) {
      auto remain = bfs_queue.front();
      bfs_queue.pop();
      auto steps = steps_dp[static_cast<size_t>(remain)];
      if (remain == 0) {
        return steps;
      }
      for (auto coin : coins) {
        if (size_t new_remain = static_cast<size_t>(remain - coin);
            remain >= coin and not steps_dp[static_cast<size_t>(new_remain)]) {
          steps_dp[new_remain] = steps + 1;
          bfs_queue.push(remain - coin);
        }
      }
    }
    return -1;
  }
};
