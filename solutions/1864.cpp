#include <string>

class Solution {
 public:
  int minSwaps(std::string s) {
    int miss_even_0 = 0, miss_odd_1 = 0;
    int miss_odd_0 = 0, miss_even_1 = 0;

    for (size_t p = 0; p < s.size(); ++p) {
      miss_even_0 += !(p % 2) and s[p] != '0';
      miss_odd_1 += (p % 2) and s[p] != '1';
      miss_odd_0 += (p % 2) and s[p] != '0';
      miss_even_1 += !(p % 2) and s[p] != '1';
    }

    bool works_even_0 = miss_even_0 == miss_odd_1;
    bool works_odd_0 = miss_odd_0 == miss_even_1;

    if (works_even_0 and works_odd_0) {
      return std::min(miss_even_0, miss_odd_0);
    } else if (works_even_0) {
      return miss_even_0;
    } else if (works_odd_0) {
      return miss_odd_0;
    }

    return -1;
  }
};
