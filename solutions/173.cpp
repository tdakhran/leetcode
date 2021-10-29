#include <stack>

class BSTIterator {
  std::stack<TreeNode *> st;

 public:
  BSTIterator(TreeNode *root) {
    while (root) {
      st.push(root);
      root = root->left;
    }
  }

  int next() {
    auto node = st.top();
    st.pop();
    auto it = node->right;
    while (it) {
      st.push(it);
      it = it->left;
    }
    return node->val;
  }

  bool hasNext() { return not st.empty(); }
};
