#include <functional>
#include <unordered_map>

class Solution {
 public:
  int pathSum(TreeNode *root, int targetSum) {
    std::unordered_map<int, int> prefix{{0, 1}};

    std::function<int(const TreeNode *, const int, const int)> dfs =
        [&dfs, &prefix](const TreeNode *node, const int acc, const int target) {
          if (not node) {
            return 0;
          }
          const int new_acc = acc + node->val;

          int result = 0;
          if (auto it = prefix.find(new_acc - target); it != end(prefix)) {
            result += it->second;
          }

          ++prefix[new_acc];
          result += dfs(node->left, new_acc, target);
          result += dfs(node->right, new_acc, target);
          --prefix[new_acc];

          return result;
        };

    return dfs(root, 0, targetSum);
  }
};
