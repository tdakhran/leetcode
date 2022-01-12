#include <algorithm>
#include <array>
#include <queue>
#include <string>
#include <vector>

class Solution {
 public:
  int findRotateSteps(std::string ring, std::string key) {
    std::array<std::vector<size_t>, 'z' - 'a' + 1> poses = {{}};
    for (size_t pos = 0; pos < ring.size(); ++pos) {
      poses[static_cast<size_t>(ring[pos] - 'a')].push_back(pos);
    }

    auto dp = std::vector<int>(ring.size(), std::numeric_limits<int>::max());
    dp.front() = 0;

    std::queue<std::pair<size_t, int>> queue;
    auto prev_ch = ring.front();

    for (auto ch : key) {
      for (auto pos : poses[static_cast<size_t>(prev_ch - 'a')]) {
        if (dp[pos] < std::numeric_limits<int>::max()) {
          queue.push({pos, dp[pos]});
          dp[pos] = std::numeric_limits<int>::max();
        }
      }
      while (not queue.empty()) {
        auto [pos_ring, sum] = queue.front();
        queue.pop();

        for (auto pos : poses[static_cast<size_t>(ch - 'a')]) {
          for (auto delta : {pos_ring - pos, pos - pos_ring}) {
            if (int new_sum =
                    sum + 1 +
                    static_cast<int>((delta + ring.size()) % ring.size());
                new_sum < dp[pos]) {
              dp[pos] = new_sum;
            }
          }
        }
      }
      prev_ch = ch;
    }

    return *std::min_element(begin(dp), end(dp));
  }
};
