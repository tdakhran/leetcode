#include <optional>

class Solution {
  std::optional<std::pair<int, int>> v(TreeNode *root, int &result) {
    if (not root) {
      return std::nullopt;
    }
    auto res = std::make_pair(root->val, root->val);
    for (auto ch : {root->left, root->right}) {
      if (auto r = v(ch, result); r) {
        res.first = std::min(r->first, res.first);
        res.second = std::max(r->second, res.second);
      }
    }
    result = std::max(result, abs(root->val - res.first));
    result = std::max(result, abs(root->val - res.second));
    return std::move(res);
  }

 public:
  int maxAncestorDiff(TreeNode *root) {
    int result = 0;
    v(root, result);
    return result;
  }
};
