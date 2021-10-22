#include <algorithm>
#include <string>
#include <vector>

class Solution {
 public:
  std::string frequencySort(std::string s) {
    std::vector<std::pair<size_t, char>> freqs(128, {0, '0'});
    for (auto c : s) {
      auto index = static_cast<size_t>(c);
      freqs[index].second = c;
      ++freqs[index].first;
    }
    std::sort(begin(freqs), end(freqs),
              std::greater<std::pair<size_t, char>>());

    size_t start_pos = 0;
    for (const auto &[freq, c] : freqs) {
      for (size_t pos = start_pos; pos < start_pos + freq; ++pos) {
        s[pos] = c;
      }
      start_pos += freq;
    }
    return s;
  }
};
