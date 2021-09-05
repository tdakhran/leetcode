#include <algorithm>
#include <string>
#include <string_view>

class Solution {
 public:
  std::string orderlyQueue(std::string s, int k) {
    // if k > 1, any permutation is possible
    if (k > 1) {
      sort(begin(s), end(s));
      return s;
    }
    // if k = 1, then only rotation possible
    std::string ss = s + s;
    std::string_view sv(ss);
    std::string_view result = sv.substr(0, s.size());
    for (size_t i = 1; i < s.size(); ++i) {
      auto subsv = sv.substr(i, s.size());
      if (subsv < result) {
        result = subsv;
      }
    }
    return std::string(result);
  }
};
