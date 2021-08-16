#include <numeric>
#include <vector>

class NumArray {
  std::vector<int> partial_sums{0};

 public:
  NumArray(std::vector<int> &nums) {
    std::partial_sum(begin(nums), end(nums), back_inserter(partial_sums));
  }

  int sumRange(int left, int right) {
    return partial_sums[right + 1] - partial_sums[left];
  }
};
