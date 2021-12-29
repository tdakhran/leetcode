#include <string>

class Solution {
 public:
  int findLUSlength(std::string a, std::string b) {
    if (a == b) {
      return -1;
    }
    return static_cast<int>(std::max(a.size(), b.size()));
  }
};
