#include <vector>

class Solution {
  TreeNode* gen(std::vector<int>& nums, int i, int j) {
    if (i >= j) {
      return nullptr;
    }
    int mi = i + (j - i) / 2;
    auto root = new TreeNode(nums[static_cast<size_t>(mi)]);
    root->left = gen(nums, i, mi);
    root->right = gen(nums, mi + 1, j);
    return root;
  }

 public:
  TreeNode* sortedArrayToBST(std::vector<int>& nums) {
    return gen(nums, 0, static_cast<int>(nums.size()));
  }
};
