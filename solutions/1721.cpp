#include <utility>

class Solution {
 public:
  ListNode* swapNodes(ListNode* head, int k) {
    auto left = head;
    while (--k) {
      left = left->next;
    }
    auto right = head;
    for (auto it = left; it->next; it = it->next) {
      right = right->next;
    }
    std::swap(left->val, right->val);
    return head;
  }
};
