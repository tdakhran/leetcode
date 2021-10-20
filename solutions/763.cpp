#include <algorithm>
#include <vector>

class Solution {
 public:
  std::vector<int> partitionLabels(std::string S) {
    constexpr size_t UNINIT = std::numeric_limits<size_t>::max();
    std::vector<std::pair<size_t, size_t>> i(26, {UNINIT, UNINIT});
    for (size_t pos = 0; pos < S.size(); ++pos) {
      size_t c = static_cast<size_t>(S[pos] - 'a');
      i[c] = {std::min(i[c].first, pos), pos};
    }
    std::sort(begin(i), end(i));

    std::vector<int> result;
    for (size_t p = 0; p < i.size(); ++p) {
      auto [start, end] = i[p];
      if (start == UNINIT) {
        continue;
      }
      for (; p + 1 < i.size() and i[p + 1].first <= end; ++p) {
        end = std::max(end, i[p + 1].second);
      }
      result.push_back(static_cast<int>(end - start + 1));
    }
    return result;
  }
};
