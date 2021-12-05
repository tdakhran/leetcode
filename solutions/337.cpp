#include <algorithm>

class Solution {
  struct State {
    int rob{0};
    int not_rob{0};

    int max() const { return std::max(rob, not_rob); }
  };
  State visit(TreeNode *root) {
    if (not root) {
      return State();
    }
    auto left = visit(root->left);
    auto right = visit(root->right);

    return {root->val + left.not_rob + right.not_rob, right.max() + left.max()};
  }

 public:
  int rob(TreeNode *root) { return visit(root).max(); }
};
