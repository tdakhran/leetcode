#include <algorithm>
#include <queue>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
    std::sort(begin(nums), end(nums));

    std::vector<std::vector<int>> result = {{}};

    std::queue<std::pair<size_t, size_t>> queue;
    queue.push({0, 0});

    while (not queue.empty()) {
      auto [start_pos, result_entry_pos] = queue.front();
      queue.pop();

      for (size_t pos = start_pos; pos < nums.size(); ++pos) {
        if (auto num = nums[pos]; pos == start_pos or nums[pos - 1] != num) {
          queue.push({pos + 1, result.size()});

          auto result_entry = result[result_entry_pos];
          result_entry.push_back(num);
          result.push_back(result_entry);
        }
      }
    }
    return result;
  }
};
