#include <vector>

class Solution {
 public:
  void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
    size_t i1 = static_cast<size_t>(m), i2 = static_cast<size_t>(n),
           insert_pos = static_cast<size_t>(n + m - 1);
    while (i1 > 0 and i2 > 0) {
      nums1[insert_pos--] =
          (nums1[i1 - 1] > nums2[i2 - 1]) ? nums1[i1-- - 1] : nums2[i2-- - 1];
    }
    while (i2 > 0) {
      nums1[insert_pos--] = nums2[i2-- - 1];
    }
  }
};
