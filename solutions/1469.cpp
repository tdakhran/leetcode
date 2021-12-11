#include <queue>
#include <vector>

class Solution {
 public:
  std::vector<int> getLonelyNodes(TreeNode *root) {
    std::vector<int> result;
    std::queue<TreeNode *> q;
    q.push(root);

    while (not q.empty()) {
      auto node = q.front();
      q.pop();
      if (not node) {
        continue;
      }

      if (node->left and not node->right) {
        result.push_back(node->left->val);
      }
      if (node->right and not node->left) {
        result.push_back(node->right->val);
      }
      q.push(node->left);
      q.push(node->right);
    }
    return result;
  }
};
