#include <algorithm>
#include <queue>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> zigzagLevelOrder(TreeNode *root) {
    std::queue<TreeNode *> q;
    std::vector<std::vector<int>> result;
    q.push(root);
    bool need_reverse = false;

    while (not q.empty()) {
      std::vector<int> level;
      auto sz = q.size();
      while (sz--) {
        auto node = q.front();
        q.pop();
        if (not node) {
          continue;
        }
        level.push_back(node->val);
        q.push(node->left);
        q.push(node->right);
      }
      if (need_reverse) {
        std::reverse(begin(level), end(level));
      }
      if (not level.empty()) {
        result.push_back(level);
      }

      need_reverse = not need_reverse;
    }
    return result;
  }
};
