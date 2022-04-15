#include <algorithm>
#include <vector>

class Solution {
 public:
  std::vector<int> sortJumbled(std::vector<int>& mapping,
                               std::vector<int>& nums) {
    auto convert = [&mapping](int a) -> int {
      int result = 0;
      int mult = 1;
      do {
        size_t digit = a % 10;
        a /= 10;
        result += mult * mapping[digit];
        mult *= 10;
      } while (a);
      return result;
    };
    std::stable_sort(begin(nums), end(nums), [&convert](int a, int b) {
      return convert(a) < convert(b);
    });
    return nums;
  }
};
