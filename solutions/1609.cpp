#include <deque>
#include <functional>

class Solution {
 public:
  const struct {
    std::function<bool(TreeNode *, TreeNode *)> comparator;
    std::function<bool(TreeNode *)> parity;
  } params[2] = {{[](TreeNode *a, TreeNode *b) { return a->val <= b->val; },
                  [](TreeNode *a) { return (a->val % 2); }},

                 {[](TreeNode *a, TreeNode *b) { return a->val >= b->val; },
                  [](TreeNode *a) { return !(a->val % 2); }}};

  bool isEvenOddTree(TreeNode *root) {
    std::deque<TreeNode *> q;
    if (root) {
      q.push_back(root);
    }
    for (size_t parity = 0; not q.empty(); parity = 1 - parity) {
      if (!is_sorted(begin(q), end(q), params[parity].comparator)) {
        return false;
      }
      if (!all_of(begin(q), end(q), params[parity].parity)) {
        return false;
      }
      auto qsize = q.size();
      while (qsize--) {
        auto node = q.front();
        q.pop_front();

        for (auto ch : {node->left, node->right}) {
          if (ch) {
            q.push_back(ch);
          }
        }
      }
    }

    return true;
  }
};
