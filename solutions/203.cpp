class Solution {
 public:
  ListNode* removeElements(ListNode* head, int val) {
    ListNode preHead;
    auto tail = &preHead;
    while (head) {
      auto next = head->next;
      if (head->val == val) {
        delete head;
      } else {
        tail = tail->next = head;
      }
      head = next;
    }
    tail->next = nullptr;
    return preHead.next;
  }
};
