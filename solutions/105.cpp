#include <functional>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
    std::unordered_map<int, size_t> inorder2pos;
    for (size_t pos = 0; pos < inorder.size(); ++pos) {
      inorder2pos[inorder[pos]] = pos;
    }
    auto it = begin(preorder);

    std::function<TreeNode*(size_t, size_t)> rec =
        [&rec, &it, &inorder2pos](size_t lo, size_t hi) -> TreeNode* {
      if (lo >= hi) {
        return nullptr;
      }

      auto val = *it++;
      auto pos = inorder2pos[val];

      auto left = rec(lo, pos);
      auto right = rec(pos + 1, hi);
      return new TreeNode(val, left, right);
    };

    return rec(0, preorder.size());
  }
};
