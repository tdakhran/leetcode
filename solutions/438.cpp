#include <array>
#include <string>
#include <vector>

class Solution {
 public:
  std::vector<int> findAnagrams(std::string s, std::string p) {
    std::array<int, 26> target_freq{0};
    for (auto c : p) {
      ++target_freq[static_cast<size_t>(c - 'a')];
    }

    std::vector<int> result;
    std::array<int, 26> current_freq{0};
    for (size_t pos = 0; pos < s.size(); ++pos) {
      ++current_freq[static_cast<size_t>(s[pos] - 'a')];
      if (pos >= p.size()) {
        --current_freq[static_cast<size_t>(s[pos - p.size()] - 'a')];
      }
      if (pos + 1 >= p.size() and current_freq == target_freq) {
        result.push_back(static_cast<int>(pos - p.size() + 1));
      }
    }
    return result;
  }
};
