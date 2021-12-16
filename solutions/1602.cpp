#include <queue>

class Solution {
 public:
  TreeNode *findNearestRightNode(TreeNode *root, TreeNode *u) {
    std::queue<TreeNode *> q;
    if (root) {
      q.push(root);
    }

    while (not q.empty()) {
      auto qsize = q.size();
      while (qsize--) {
        auto node = q.front();
        q.pop();

        if (node == u) {
          return qsize ? q.front() : nullptr;
        }

        for (auto ch : {node->left, node->right}) {
          if (ch) {
            q.push(ch);
          }
        }
      }
    }
    return nullptr;
  }
};
