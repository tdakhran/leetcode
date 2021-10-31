#include <set>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  std::vector<int> topKFrequent(std::vector<int> &nums, int k) {
    std::unordered_map<int, size_t> freq;
    for (auto num : nums) {
      ++freq[num];
    }

    std::set<std::pair<size_t, int>> most_freq;
    for (const auto &[value, count] : freq) {
      most_freq.insert({count, value});
      if (most_freq.size() > static_cast<size_t>(k)) {
        most_freq.erase(begin(most_freq));
      }
    }

    std::vector<int> result;
    for (const auto &[_, value] : most_freq) {
      result.push_back(value);
    }

    return result;
  }
};
