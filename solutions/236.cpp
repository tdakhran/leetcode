#include <variant>

class Solution {
  using LCANodeOrSeenCount = std::variant<TreeNode*, size_t>;

  LCANodeOrSeenCount postorder(TreeNode* node, TreeNode* p, TreeNode* q) {
    if (not node) {
      return LCANodeOrSeenCount(0);
    }

    size_t seen_count = (node == p) + (node == q);

    for (auto child : {node->left, node->right}) {
      auto lca_node_or_seen_count = postorder(child, p, q);
      if (std::holds_alternative<TreeNode*>(lca_node_or_seen_count)) {
        return lca_node_or_seen_count;
      }
      seen_count += std::get<size_t>(lca_node_or_seen_count);
    }

    return seen_count == 2 ? LCANodeOrSeenCount(node)
                           : LCANodeOrSeenCount(seen_count);
  }

 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    return std::get<TreeNode*>(postorder(root, p, q));
  }
};
