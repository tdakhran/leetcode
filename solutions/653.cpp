#include <cassert>
#include <stack>

struct Iterator {
  virtual ~Iterator();
  virtual TreeNode *left(TreeNode *root) const = 0;
  virtual TreeNode *right(TreeNode *root) const = 0;

  int operator*() const { return stack_.top()->val; }

  operator bool() const { return not stack_.empty(); }

  bool operator!=(const Iterator &other) const {
    assert(*this and other);
    return stack_.top() != other.stack_.top();
  }

  void operator++() {
    assert(*this);
    auto root = stack_.top();
    stack_.pop();
    root = right(root);
    while (root) {
      stack_.push(root);
      root = left(root);
    }
  }

 protected:
  void init(TreeNode *root) {
    while (root) {
      stack_.push(root);
      root = left(root);
    }
  }

 private:
  std::stack<TreeNode *> stack_;
};
Iterator::~Iterator() = default;

struct ForwardIterator : public Iterator {
  explicit ForwardIterator(TreeNode *root) { init(root); }
  TreeNode *left(TreeNode *root) const final;
  TreeNode *right(TreeNode *root) const final;
};
TreeNode *ForwardIterator::left(TreeNode *root) const { return root->left; }
TreeNode *ForwardIterator::right(TreeNode *root) const { return root->right; }

struct ReverseIterator : public Iterator {
  explicit ReverseIterator(TreeNode *root) { init(root); }
  TreeNode *left(TreeNode *root) const final;
  TreeNode *right(TreeNode *root) const final;
};
TreeNode *ReverseIterator::left(TreeNode *root) const { return root->right; }
TreeNode *ReverseIterator::right(TreeNode *root) const { return root->left; }

class Solution {
 public:
  bool findTarget(TreeNode *root, int k) {
    ForwardIterator lo(root);

    ReverseIterator hi(root);

    while (lo != hi) {
      auto sum = *lo + *hi;
      if (sum == k) {
        return true;
      } else if (sum < k) {
        ++lo;
      } else {
        ++hi;
      }
    }

    return false;
  }
};
