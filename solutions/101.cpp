#include <functional>

class Solution {
 public:
  bool isSymmetric(TreeNode *root) {
    std::function<bool(TreeNode *, TreeNode *)> isSymmetricRecursive =
        [&isSymmetricRecursive](TreeNode *l, TreeNode *r) {
          if (!l and !r) {
            return true;
          }
          if (l and r) {
            return l->val == r->val and
                   isSymmetricRecursive(l->left, r->right) and
                   isSymmetricRecursive(l->right, r->left);
          }
          return false;
        };
    return root ? isSymmetricRecursive(root->left, root->right) : true;
  }
};
