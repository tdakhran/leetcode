class Solution {
 public:
  int sumOfLeftLeaves(TreeNode *root) {
    if (not root) {
      return 0;
    }

    int result = 0;
    if (root->left and not root->left->left and not root->left->right) {
      result += root->left->val;
    }
    return result + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
  }
};
