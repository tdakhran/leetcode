class Solution {
 public:
  ListNode* reverseList(ListNode* head) {
    ListNode* tail = nullptr;
    while (head) {
      auto next = head->next;
      head->next = tail;
      tail = head;
      head = next;
    }
    return tail;
  }
};
