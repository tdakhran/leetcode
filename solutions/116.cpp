class Solution {
 public:
  Node* connect(Node* root) {
    if (not root) {
      return root;
    }
    auto level = root;
    while (level->left) {
      auto it = level;
      do {
        auto next = it->next;
        it->left->next = it->right;
        it->right->next = next ? next->left : nullptr;
        it = next;
      } while (it);

      level = level->left;
    }
    return root;
  }
};
