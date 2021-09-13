#include <functional>
#include <vector>

class Solution {
 public:
  std::vector<int> postorderTraversal(TreeNode *root) {
    std::vector<int> result;
    std::function<void(TreeNode *)> postorder = [&postorder,
                                                &result](TreeNode *node) {
      if (not node) {
        return;
      }
      postorder(node->left);
      postorder(node->right);
      result.push_back(node->val);
    };
    postorder(root);
    return result;
  }
};
