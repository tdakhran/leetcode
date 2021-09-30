#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <vector>

class Solution {
  static constexpr bool is_bit_set(int value, size_t bit) {
    return value & (1 << bit);
  }
  static int clear_bit(int value, size_t bit) { return value & ~(1 << bit); }

 public:
  bool canPartitionKSubsets(std::vector<int>& nums, int k) {
    auto total_sum = std::accumulate(begin(nums), end(nums), 0);
    if (total_sum % k) {
      return false;
    }
    auto chunk_sum = total_sum / k;
    std::sort(begin(nums), end(nums), std::greater<int>());
    std::unordered_map<int, bool> cache;

    std::function<bool(int, int)> rec = [&rec, &nums, &chunk_sum, &cache](
                                            int remaining, int mask) {
      if (remaining < 0) {
        return false;
      }
      if (mask == 0) {
        return remaining == 0;
      }
      if (remaining == 0) {
        return rec(chunk_sum, mask);
      }
      auto hash = (remaining << 16) | mask;
      if (auto it = cache.find(hash); it != end(cache)) {
        return it->second;
      }

      for (size_t i = 0; i < nums.size(); ++i) {
        if (is_bit_set(mask, i) and
            rec(remaining - nums[i], clear_bit(mask, i))) {
          return true;
        }
      }
      cache[hash] = false;
      return false;
    };
    return rec(chunk_sum, (1 << nums.size()) - 1);
  }
};
