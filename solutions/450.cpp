class Solution {
 public:
  TreeNode* deleteNode(TreeNode* root, int key) {
    if (not root) return nullptr;
    if (key < root->val) {
      root->left = deleteNode(root->left, key);
    } else if (key > root->val) {
      root->right = deleteNode(root->right, key);
    } else {
      if (!root->left || !root->right) {
        root = root->left ? root->left : root->right;
      } else {
        // find leftmost of right
        auto leftmost = root->right;
        while (leftmost and leftmost->left) {
          leftmost = leftmost->left;
        }
        root->val = leftmost->val;
        root->right = deleteNode(root->right, leftmost->val);
      }
    }
    return root;
  }
};
