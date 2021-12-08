#include <cmath>

class Solution {
  int sum(TreeNode *root, int &result) {
    if (not root) {
      return 0;
    }
    auto l = sum(root->left, result);
    auto r = sum(root->right, result);
    result += std::abs(l - r);
    return root->val + l + r;
  }

 public:
  int findTilt(TreeNode *root) {
    int result = 0;
    sum(root, result);
    return result;
  }
};
