class Solution {
  bool isSame(TreeNode* s, TreeNode* t) {
    if ((s and not t) or (t and not s)) {
      return false;
    }
    if (not s and not t) {
      return true;
    }

    return s->val == t->val and isSame(s->left, t->left) and
           isSame(s->right, t->right);
  }

 public:
  bool isSubtree(TreeNode* s, TreeNode* t) {
    return isSame(s, t) or
           (s and (isSubtree(s->left, t) or isSubtree(s->right, t)));
  }
};
