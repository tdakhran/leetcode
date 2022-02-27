#include <functional>
#include <vector>

class Solution {
 public:
  int widthOfBinaryTree(TreeNode *root) {
    std::vector<std::pair<size_t, size_t>> edges;
    std::function<size_t(const TreeNode *const, const size_t, const size_t)>
        dfs = [&](const TreeNode *const node, const size_t depth,
                  const size_t pos) -> size_t {
      if (not node) {
        return 0;
      }

      if (edges.size() <= depth) {
        edges.push_back({std::numeric_limits<uint64_t>::max(),
                         std::numeric_limits<uint64_t>::min()});
      }

      edges[depth].first = std::min(edges[depth].first, pos);
      edges[depth].second = std::max(edges[depth].second, pos);

      size_t result = edges[depth].second - edges[depth].first + 1;

      result = std::max(result, dfs(node->left, depth + 1, 2 * pos));
      result = std::max(result, dfs(node->right, depth + 1, 2 * pos + 1));

      return result;
    };

    return static_cast<int>(dfs(root, 0, 0));
  }
};
