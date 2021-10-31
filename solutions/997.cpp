#include <vector>

class Solution {
 public:
  int findJudge(size_t n, std::vector<std::vector<int>>& trust) {
    std::vector<int> trusted_by(n + 1), trust_to(n + 1);

    for (const auto& t : trust) {
      ++trusted_by[static_cast<size_t>(t[1])];
      ++trust_to[static_cast<size_t>(t[0])];
    }
    size_t candidate = 0;
    for (size_t id = 1; id <= n; ++id) {
      if (not trust_to[id] and trusted_by[id] == static_cast<int>(n - 1)) {
        if (not candidate) {
          candidate = id;
        } else {
          return -1;
        }
      }
    }
    return candidate ? static_cast<int>(candidate) : -1;
  }
};
