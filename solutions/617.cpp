class Solution {
 public:
  TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
    TreeNode *result{nullptr};
    if (root1 and root2) {
      result = root1;
      result->val += root2->val;
    } else if (root1) {
      result = root1;
    } else if (root2) {
      result = root2;
    }

    if (result) {
      result->left = mergeTrees(root1 ? root1->left : nullptr,
                                root2 ? root2->left : nullptr);
      result->right = mergeTrees(root1 ? root1->right : nullptr,
                                 root2 ? root2->right : nullptr);
    }

    return result;
  }
};
