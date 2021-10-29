#include <functional>

class Solution {
 public:
  int kthSmallest(TreeNode *root, int k) {
    std::function<int(TreeNode *)> smallest = [&smallest, &k](TreeNode *node) {
      if (not node) {
        return -1;
      }

      if (auto left = smallest(node->left); left >= 0) {
        return left;
      }
      if (--k == 0) {
        return node->val;
      }
      return smallest(node->right);
    };
    return smallest(root);
  }
};
