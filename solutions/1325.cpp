class Solution {
 public:
  TreeNode *removeLeafNodes(TreeNode *node, int target) {
    if (not node) {
      return nullptr;
    }

    node->left = removeLeafNodes(node->left, target);
    node->right = removeLeafNodes(node->right, target);

    if (not node->left and not node->right and node->val == target) {
      return nullptr;
    }
    return node;
  }
};
