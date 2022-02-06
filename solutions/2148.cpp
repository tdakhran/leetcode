#include <algorithm>
#include <vector>

class Solution {
 public:
  int countElements(std::vector<int>& nums) {
    const auto [min_it, max_it] = std::minmax_element(begin(nums), end(nums));

    return static_cast<int>(
        std::count_if(begin(nums), end(nums),
                      [min_val = *min_it, max_val = *max_it](int val) {
                        return (min_val != val) and (max_val != val);
                      }));
  }
};
