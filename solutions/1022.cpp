#include <initializer_list>

class Solution {
  int dfs(TreeNode *r, int cur) {
    cur = (cur << 1) | r->val;
    if (not r->left and not r->right) {
      return cur;
    }
    int sum = 0;
    for (auto ch : {r->left, r->right}) {
      if (ch) {
        sum += dfs(ch, cur);
      }
    }
    return sum;
  }

 public:
  int sumRootToLeaf(TreeNode *root) { return dfs(root, 0); }
};
