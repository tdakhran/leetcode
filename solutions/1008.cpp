#include <stack>
#include <vector>

class Solution {
 public:
  TreeNode *bstFromPreorder(std::vector<int> &preorder) {
    std::stack<TreeNode *> st;
    auto root = new TreeNode(preorder.front());
    st.push(root);

    for (size_t pos = 1; pos < preorder.size(); ++pos) {
      auto val = preorder[pos];
      auto node = new TreeNode(val);

      if (val < st.top()->val) {
        st.top()->left = node;
        st.push(node);
        continue;
      }
      TreeNode *cand = nullptr;
      while (not st.empty() and st.top()->val < val) {
        cand = st.top();
        st.pop();
      }
      if (cand) {
        cand->right = node;
      }
      st.push(node);
    }

    return root;
  }
};
