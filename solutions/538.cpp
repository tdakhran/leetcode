#include <functional>

class Solution {
  int acc = 0;

 public:
  TreeNode *convertBST(TreeNode *root) {
    if (root) {
      convertBST(root->right);
      root->val = (acc += root->val);
      convertBST(root->left);
    }
    return root;
  }
};
