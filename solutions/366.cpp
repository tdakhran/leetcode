#include <functional>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> findLeaves(TreeNode *root) {
    std::vector<std::vector<int>> result;
    std::function<size_t(TreeNode *)> dfs = [&dfs, &result](TreeNode *node) {
      if (not node) {
        return 0ul;
      }
      auto level = std::max(dfs(node->left), dfs(node->right));

      if (level >= result.size()) {
        result.resize(level + 1);
      }

      result[level].push_back(node->val);
      return level + 1;
    };

    dfs(root);

    return result;
  }
};
