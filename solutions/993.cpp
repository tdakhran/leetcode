#include <queue>

class Solution {
 public:
  bool isCousins(TreeNode *root, int x, int y) {
    std::queue<TreeNode *> q;
    q.push(root);

    while (not q.empty()) {
      auto sz = q.size();
      size_t match = 0;

      while (sz--) {
        auto node = q.front();
        q.pop();
        if (not node) {
          continue;
        }
        if (node->val == x or node->val == y) {
          if (sz + 1 == match) {
            return false;
          }
          if (match) {
            return true;
          }
          match = sz;
        }

        q.push(node->left);
        q.push(node->right);
        q.push(nullptr);
      }
    }
    return false;
  }
};
