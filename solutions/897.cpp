struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

#include <utility>

class Solution {
 public:
  std::pair<TreeNode *, TreeNode *> inorder(TreeNode *node) {
    if (not node) {
      return std::make_pair(nullptr, nullptr);
    }

    auto [head, tail] = inorder(node->left);
    if (not head) {
      head = node;
      tail = node;
    } else {
      tail = tail->right = node;
      tail->left = nullptr;
    }

    if (auto [rhead, rtail] = inorder(tail->right); rhead) {
      tail = tail->right = rhead;
      tail = rtail;
    }
    return std::make_pair(head, tail);
  }

  TreeNode *increasingBST(TreeNode *root) { return inorder(root).first; }
};
