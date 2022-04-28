#include <algorithm>
#include <vector>

class Solution {
 public:
  int largestInteger(int num) {
    std::vector<int> parity;
    std::vector<int> odd_digits;
    std::vector<int> even_digits;

    for (size_t idx = 0; num; ++idx) {
      auto digit = num % 10;
      num /= 10;
      parity.push_back(digit % 2);
      (digit % 2) ? odd_digits.push_back(digit) : even_digits.push_back(digit);
    }

    sort(begin(odd_digits), end(odd_digits), std::greater<int>());
    sort(begin(even_digits), end(even_digits), std::greater<int>());
    std::reverse(begin(parity), end(parity));

    for (auto it = parity.begin(), io = begin(odd_digits),
              ie = begin(even_digits);
         it != end(parity); ++it) {
      auto &i = *it ? io : ie;
      num = num * 10 + *i++;
    }
    return num;
  }
};
