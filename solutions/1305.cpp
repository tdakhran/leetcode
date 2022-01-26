#include <algorithm>
#include <stack>
#include <vector>

class BSTIterator {
 public:
  using value_type = int;
  using iterator_category = std::forward_iterator_tag;
  using difference_type = std::ptrdiff_t;
  using pointer = int*;
  using reference = int&;

  explicit BSTIterator(TreeNode* root) {
    if (root) {
      st.push({root, false});
    }
  }

  bool operator!=(const BSTIterator& other) const {
    return st.size() != other.st.size() or st != other.st;
  }
  int operator*() {
    while (not st.top().second) {
      auto l = st.top().first->left;
      st.top().second = true;
      if (l) {
        st.push({l, false});
      }
    }
    return st.top().first->val;
  }
  void operator++() {
    auto r = st.top().first->right;
    st.pop();
    if (r) {
      st.push({r, false});
    }
  }

 private:
  std::stack<std::pair<TreeNode*, bool>> st;
};

class Solution {
 public:
  std::vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
    std::vector<int> result;
    std::merge(BSTIterator(root1), BSTIterator(nullptr), BSTIterator(root2),
               BSTIterator(nullptr), std::back_inserter(result));
    return result;
  }
};
