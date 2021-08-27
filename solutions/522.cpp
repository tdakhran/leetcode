#include <string>
#include <vector>

class Solution {
 public:
  int findLUSlength(std::vector<std::string>& strs) {
    auto is_subseq_1xN = [](const auto& vec_a, auto ia) {
      auto is_subseq_1x1 = [](const std::string& a, const std::string& b) {
        auto iter_a = begin(a);
        for (auto c : b) {
          if (*iter_a == c) {
            ++iter_a;
          }
        }
        return iter_a == end(a);
      };

      for (auto ib = begin(vec_a); ib != end(vec_a); ++ib) {
        if (ia == ib) {
          continue;
        }
        if (is_subseq_1x1(*ia, *ib)) {
          return true;
        }
      }
      return false;
    };

    int result = -1;
    for (auto ia = strs.cbegin(); ia != strs.cend(); ++ia) {
      if (not is_subseq_1xN(strs, ia)) {
        result = std::max<int>(result, static_cast<int>(ia->size()));
      }
    }
    return result;
  }
};
