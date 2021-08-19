#include <cinttypes>
#include <utility>

class Solution {
  int64_t sum(TreeNode *root) {
    if (not root) {
      return 0;
    }
    return root->val + sum(root->left) + sum(root->right);
  }

  std::pair<int64_t, int64_t> calculate(TreeNode *root,
                                        const int64_t total_sum) {
    if (not root) {
      return {0, 0};
    }
    int64_t current_sum = root->val;
    int64_t current_best_result = 0;

    for (auto child : {root->left, root->right}) {
      auto [child_sum, child_best_result] = calculate(child, total_sum);
      current_sum += child_sum;
      current_best_result = max({current_best_result, child_best_result,
                                 child_sum * (total_sum - child_sum)});
    }
    return {current_sum, current_best_result};
  }

 public:
  int maxProduct(TreeNode *root) {
    return calculate(root, sum(root)).second % 1'000'000'007;
  }
};
