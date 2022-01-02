#include <cmath>

class Solution {
 public:
  int closestValue(TreeNode *root, double target) {
    auto it = root;
    int result = root->val;
    while (it) {
      if (std::abs(target - it->val) < std::abs(target - result)) {
        result = it->val;
      }
      it = (target < it->val) ? it->left : it->right;
    }
    return result;
  }
};
