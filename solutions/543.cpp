#include <algorithm>
#include <utility>

class Solution {
 public:
  std::pair<int, int> ll(TreeNode *root) {
    if (not root) {
      return {0, 0};
    }
    auto l = ll(root->left);
    auto r = ll(root->right);
    auto res = std::max(l.first, r.first);
    return {std::max(res, l.second + r.second + 1),
            std::max(l.second, r.second) + 1};
  }
  int diameterOfBinaryTree(TreeNode *root) {
    auto res = ll(root);
    return std::max(std::max(res.first, res.second) - 1, 0);
  }
};
