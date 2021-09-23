#include <optional>
#include <vector>

class Solution {
 public:
  int getMaxLen(std::vector<int>& nums) {
    int count_negative = 0;
    int frame_start = -1;
    std::optional<int> first_negative_position;
    int result = 0;
    for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
      int n = nums[static_cast<size_t>(i)];
      if (n == 0) {
        count_negative = 0;
        frame_start = i;
        first_negative_position = std::nullopt;
      } else if (n < 0) {
        ++count_negative;
        first_negative_position =
            first_negative_position ? *first_negative_position : i;
      }
      result = std::max(
          result,
          i - ((count_negative % 2) ? *first_negative_position : frame_start));
    }
    return result;
  }
};
