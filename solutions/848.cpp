#include <string>
#include <vector>

class Solution {
 public:
  std::string shiftingLetters(std::string s, std::vector<int>& shifts) {
    int acc = 0;
    for (size_t pos = s.size(); pos > 0; --pos) {
      acc = (acc + shifts[pos - 1]) % 26;
      s[pos - 1] = 'a' + ((s[pos - 1] - 'a' + acc) % 26);
    }
    return s;
  }
};
