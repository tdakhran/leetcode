#include <string>
#include <unordered_set>
#include <vector>

class Solution {
 public:
  std::vector<std::string> findRepeatedDnaSequences(std::string ss) {
    std::string_view s = ss;
    std::unordered_set<std::string_view> result;
    std::unordered_set<std::string_view> cand;
    for (size_t k = 0; k + 10 <= s.size(); ++k) {
      std::string_view sv = s.substr(k, 10);
      if (result.count(sv)) {
        continue;
      }
      if (not cand.insert(sv).second) {
        result.insert(sv);
        cand.erase(sv);
      }
    }
    return std::vector<std::string>(begin(result), end(result));
  }
};
