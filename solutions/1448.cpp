#include <limits>

class Solution {
 public:
  int goodNodes(TreeNode* root,
                int max_value_observed = std::numeric_limits<int>::min()) {
    if (not root) {
      return 0;
    }

    int retval = root->val >= max_value_observed;

    for (auto child : {root->left, root->right}) {
      retval += goodNodes(child, max(max_value_observed, root->val));
    }

    return retval;
  }
};
