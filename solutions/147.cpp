#include <limits>

class Solution {
 public:
  ListNode* insertionSortList(ListNode* head) {
    ListNode preHead(std::numeric_limits<int>::min(), head);

    auto tail = &preHead;
    while (tail->next) {
      if (tail->val <= tail->next->val) {
        tail = tail->next;
        continue;
      }
      auto node = tail->next;
      tail->next = node->next;
      node->next = nullptr;
      auto it = &preHead;
      while (it->next and it->next->val <= node->val) {
        it = it->next;
      }
      node->next = it->next;
      it->next = node;
    }
    return preHead.next;
  }
};
