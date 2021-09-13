#include <functional>
#include <vector>

class Solution {
 public:
  std::vector<int> inorderTraversal(TreeNode *root) {
    std::vector<int> result;
    std::function<void(TreeNode *)> inorder = [&inorder,
                                               &result](TreeNode *node) {
      if (not node) {
        return;
      }

      inorder(node->left);
      result.push_back(node->val);
      inorder(node->right);
    };
    inorder(root);
    return result;
  }
};
