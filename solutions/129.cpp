class Solution {
 public:
  int sumNumbers(TreeNode *root, int accumulator = 0) {
    if (not root) {
      return 0;
    }

    accumulator = accumulator * 10 + root->val;
    if (not root->left and not root->right) {
      return accumulator;
    }
    return sumNumbers(root->left, accumulator) +
           sumNumbers(root->right, accumulator);
  }
};
