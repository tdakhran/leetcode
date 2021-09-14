#include <algorithm>
class Solution {
 public:
  int maxDepth(TreeNode *root) {
    return root ? 1 + std::max(maxDepth(root->left), maxDepth(root->right)) : 0;
  }
};
