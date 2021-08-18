#include <string>
#include <utility>

class Solution {
 public:
  int numDecodings(std::string s) {
    // track how number of ways to decode will change by appending single digit
    std::pair<int, char> prelast{1, '0'};
    int last = 1;
    for (auto c : s) {
      int new_last = 0;
      // append digit to s[0: i - 2] and test if (s[i-1]s[i]) maps to letter
      if (prelast.second == '1' or (prelast.second == '2' and c < '7')) {
        new_last += prelast.first;
      }
      // append digit to s[0: i - 1] and test if (s[i]) maps to letter
      if (c != '0') {
        new_last += last;
      }
      prelast = {last, c};
      last = new_last;
    }
    return last;
  }
};
