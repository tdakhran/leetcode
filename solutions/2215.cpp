#include <algorithm>
#include <set>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> findDifference(std::vector<int>& nums1,
                                               std::vector<int>& nums2) {
    std::set s1(begin(nums1), end(nums1));
    std::set s2(begin(nums2), end(nums2));

    std::vector<std::vector<int>> result(2);
    std::set_difference(begin(s1), end(s1), begin(s2), end(s2),
                        std::back_inserter(result.front()));
    std::set_difference(begin(s2), end(s2), begin(s1), end(s1),
                        std::back_inserter(result.back()));

    return result;
  }
};
