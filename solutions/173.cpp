#include <stack>

class BSTIterator {
  std::stack<TreeNode *> st;

  void push_left(TreeNode *node) {
    while (node) {
      st.push(node);
      node = node->left;
    }
  }

 public:
  BSTIterator(TreeNode *root) { push_left(root); }

  int next() {
    auto node = st.top();
    st.pop();
    push_left(node->right);
    return node->val;
  }

  bool hasNext() { return not st.empty(); }
};
