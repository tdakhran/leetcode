#include <functional>
#include <vector>

class Solution {
 public:
  std::vector<int> preorderTraversal(TreeNode *root) {
    std::vector<int> result;
    std::function<void(TreeNode *)> preorder = [&preorder,
                                                &result](TreeNode *node) {
      if (not node) {
        return;
      }
      result.push_back(node->val);
      preorder(node->left);
      preorder(node->right);
    };
    preorder(root);
    return result;
  }
};
