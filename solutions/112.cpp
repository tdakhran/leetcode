class Solution {
 public:
  bool hasPathSum(TreeNode* root, int targetSum) {
    if (not root) {
      return false;
    }
    auto residual = targetSum - root->val;
    if (not root->left and not root->right and residual == 0) {
      return true;
    }
    return hasPathSum(root->left, residual) or
           hasPathSum(root->right, residual);
  }
};
