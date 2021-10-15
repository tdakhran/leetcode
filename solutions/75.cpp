#include <vector>

class Solution {
 public:
  void sortColors(std::vector<int>& nums) {
    size_t insert_pos_0 = 0;
    size_t insert_pos_2 = nums.size() - 1;
    for (size_t pos = 0; pos <= insert_pos_2 and insert_pos_0 < insert_pos_2;
         ++pos) {
      auto& color = nums[pos];
      if (color == 0) {
        std::swap(color, nums[insert_pos_0]);
        ++insert_pos_0;
      } else if (color == 2) {
        std::swap(color, nums[insert_pos_2]);
        --insert_pos_2;
        --pos;
      }
    }
  }
};
