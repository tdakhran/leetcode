class Solution {
 public:
  void reorderList(ListNode* head) {
    auto slow = head;
    auto fast = head;
    while (fast and fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    auto part2 = slow->next;
    slow->next = nullptr;
    ListNode* revpart2 = nullptr;
    while (part2) {
      auto tmp = part2;
      part2 = part2->next;
      tmp->next = revpart2;
      revpart2 = tmp;
    }

    auto tail = head;
    while (revpart2) {
      auto tmp = revpart2;
      revpart2 = revpart2->next;
      tmp->next = tail->next;
      tail->next = tmp;
      tail = tail->next->next;
    }
  }
};
