#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
 public:
  std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
    std::vector<std::unordered_set<int>> buckets(nums.size() + 1);
    std::unordered_map<int, size_t> freqs;

    for (auto n : nums) {
      auto freq = ++freqs[n];
      if (freq > 1) {
        buckets[freq - 1].erase(n);
      }
      buckets[freq].insert(n);
    }

    std::vector<int> result;
    for (auto bucket = buckets.rbegin(); bucket != buckets.rend(); ++bucket) {
      for (auto e : *bucket) {
        result.push_back(e);
        if (result.size() == static_cast<size_t>(k)) {
          return result;
        }
      }
    }
    return result;
  }
};
