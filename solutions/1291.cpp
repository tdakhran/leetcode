#include <set>
#include <vector>

class Solution {
 public:
  std::vector<int> sequentialDigits(int low, int high) {
    std::set<int> result;
    size_t mlen = std::to_string(low).size();
    size_t len = std::to_string(high).size();
    for (size_t k = mlen; k <= len; ++k) {
      for (char c = '1'; c <= '9'; ++c) {
        std::string cur;
        for (char t = c; t <= '9' and cur.size() < k; ++t) {
          cur.push_back(t);
        }

        int d = stoi(cur);
        if (d <= high and d >= low) {
          result.insert(d);
        }
      }
    }
    return std::vector(begin(result), end(result));
  }
};
