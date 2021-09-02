#include <vector>

class Solution {
  std::vector<TreeNode *> generateTreesRecursive(int from, int to) {
    if (from > to) {
      return {nullptr};
    }
    std::vector<TreeNode *> result;
    for (int i = from; i <= to; ++i) {
      auto left = generateTreesRecursive(from, i - 1);
      auto right = generateTreesRecursive(i + 1, to);
      for (auto l : left) {
        for (auto r : right) {
          result.push_back(new TreeNode(i, l, r));
        }
      }
    }
    return result;
  }

 public:
  std::vector<TreeNode *> generateTrees(int n) {
    return generateTreesRecursive(1, n);
  }
};
