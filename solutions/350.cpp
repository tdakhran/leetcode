#include <algorithm>
#include <vector>

class Solution {
 public:
  std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::sort(begin(nums1), end(nums1));
    std::sort(begin(nums2), end(nums2));

    std::vector<int> result;
    std::set_intersection(begin(nums1), end(nums1), begin(nums2), end(nums2),
                          back_inserter(result));

    return result;
  }
};
