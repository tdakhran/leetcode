#include <functional>

class Solution {
 public:
  bool isValidBST(TreeNode *r) {
    TreeNode *prev = nullptr;

    std::function<bool(TreeNode *)> isValidBSTRecursive =
        [&prev, &isValidBSTRecursive](TreeNode *root) {
          if (not root) {
            return true;
          }
          if (not isValidBSTRecursive(root->left)) {
            return false;
          }
          if (prev and prev->val >= root->val) {
            return false;
          }
          prev = root;
          return isValidBSTRecursive(root->right);
        };
    return isValidBSTRecursive(r);
  }
};
