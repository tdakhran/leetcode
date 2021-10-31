#include <algorithm>

class Solution {
 public:
  std::vector<std::vector<int> > permuteUnique(std::vector<int> &nums) {
    std::sort(nums.begin(), nums.end());

    std::vector<std::vector<int> > result;
    std::function<void(size_t, size_t, std::vector<int>)> backtrack =
        [&backtrack, &result](size_t lo, size_t hi, std::vector<int> current) {
          if (lo == hi - 1) {
            result.push_back(current);
            return;
          }
          for (size_t pos = lo; pos < hi; pos++) {
            if (lo != pos && current[lo] == current[pos]) {
              continue;
            }
            std::swap(current[lo], current[pos]);
            backtrack(lo + 1, hi, current);
          }
        };
    backtrack(0, nums.size(), nums);
    return result;
  }
};
