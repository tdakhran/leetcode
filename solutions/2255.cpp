#include <algorithm>
#include <string>
#include <vector>

class Solution {
 public:
  int countPrefixes(std::vector<std::string>& words, std::string s) {
    return static_cast<int>(std::count_if(
        begin(words), end(words), [&s](std::string const& prefix) {
          return std::mismatch(begin(prefix), end(prefix), begin(s)).first ==
                 end(prefix);
        }));
  }
};
