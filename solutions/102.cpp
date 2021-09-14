#include <queue>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> levelOrder(TreeNode *root) {
    // bfs
    std::vector<std::vector<int>> result;
    std::queue<TreeNode *> queue;

    if (root) {
      queue.push(root);
    }
    while (not queue.empty()) {
      auto level_size = queue.size();
      std::vector<int> level_result;
      while (level_size--) {
        auto node = queue.front();
        queue.pop();
        level_result.push_back(node->val);
        if (node->left) {
          queue.push(node->left);
        }
        if (node->right) {
          queue.push(node->right);
        }
      }
      result.push_back(std::move(level_result));
    }
    return result;
  }
};
