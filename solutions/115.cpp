#include <string>
#include <vector>

class Solution {
 public:
  int numDistinct(std::string s, std::string t) {
    std::vector<int> cache(t.size() + 1, 0);
    cache.front() = 1;
    for (auto c : s) {
      for (size_t pos = t.size(); pos > 0; --pos) {
        cache[pos] =
            (cache[pos] + cache[pos - 1] * (c == t[pos - 1])) % 1'000'000'007;
      }
    }
    return cache.back();
  }
};
