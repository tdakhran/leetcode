#include <queue>
#include <vector>

class Solution {
 public:
  std::vector<int> rightSideView(TreeNode *root) {
    std::vector<int> result;
    std::queue<TreeNode *> q;
    if (root) {
      q.push(root);
    }
    while (not q.empty()) {
      result.push_back(q.front()->val);
      auto level_size = q.size();
      while (level_size--) {
        auto node = q.front();
        q.pop();
        for (auto child : {node->right, node->left}) {
          if (child) {
            q.push(child);
          }
        }
      }
    }
    return result;
  }
};
