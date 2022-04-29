class Solution {
  TreeNode *tail;
  void preorder(TreeNode *root) {
    if (not root) {
      return;
    }
    auto left = root->left;
    auto right = root->right;
    tail = tail->right = root;
    root->left = nullptr;
    preorder(left);
    preorder(right);
  }

 public:
  void flatten(TreeNode *root) {
    TreeNode node;
    tail = &node;
    preorder(root);
  }
};
