#include <functional>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> pathSum(TreeNode *root, int targetSum) {
    std::vector<std::vector<int>> result;
    std::vector<int> current_path;

    std::function<void(TreeNode *, int)> dfs = [&dfs, &current_path, &result](
                                                   TreeNode *n, int residual) {
      if (not n) {
        return;
      }
      residual -= n->val;
      current_path.push_back(n->val);
      dfs(n->left, residual);
      dfs(n->right, residual);
      if (not n->left and not n->right and not residual) {
        result.push_back(current_path);
      }
      current_path.pop_back();
    };
    dfs(root, targetSum);
    return result;
  }
};
