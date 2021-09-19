class Solution {
 public:
  TreeNode *searchBST(TreeNode *root, int val) {
    if (not root) {
      return nullptr;
    }
    if (val < root->val) {
      return searchBST(root->left, val);
    } else if (val > root->val) {
      return searchBST(root->right, val);
    }
    return root;
  }
};