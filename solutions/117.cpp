#include <initializer_list>

class Solution {
 public:
  Node* connect(Node* root) {
    auto current = root;
    while (current) {
      Node* next = nullptr;
      Node* prev = nullptr;
      for (auto it = current; it != nullptr; it = it->next) {
        for (auto ch : {it->left, it->right}) {
          if (ch) {
            if (not prev) {
              prev = ch;
              next = ch;
            } else {
              prev->next = ch;
              prev = ch;
            }
          }
        }
      }
      current = next;
    }
    return root;
  }
};
