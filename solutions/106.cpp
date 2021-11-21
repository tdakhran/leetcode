#include <vector>

class Solution {
  TreeNode* rec(const std::vector<int>& in, const std::vector<int>& post,
                int in_lo, int in_hi, int post_lo, int post_hi) {
    if (in_lo > in_hi) {
      return nullptr;
    }

    int val = post[static_cast<size_t>(post_hi)];
    int rootindex = in_lo;
    for (int i = in_lo; i <= in_hi; i++) {
      if (in[static_cast<size_t>(i)] == val) {
        rootindex = i;
        break;
      }
    }

    return new TreeNode(val,
                        rec(in, post, in_lo, rootindex - 1, post_lo,
                            rootindex - 1 - in_lo + post_lo),
                        rec(in, post, rootindex + 1, in_hi,
                            rootindex - in_lo + post_lo, post_hi - 1));
  }

 public:
  TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder) {
    auto size = static_cast<int>(inorder.size());
    return rec(inorder, postorder, 0, size - 1, 0, size - 1);
  }
};
