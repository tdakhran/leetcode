class Solution {
 public:
  ListNode* reverseBetween(ListNode* head, int left, int right) {
    ListNode preHead(0);
    auto tail = &preHead;
    auto to_reverse = right - left + 1;

    // non reversed head
    while (--left) {
      tail = tail->next = head;
      head = head->next;
    }
    tail->next = nullptr;
    // reversed body
    auto insert = tail;
    tail = head;
    while (to_reverse--) {
      auto node = head;
      head = head->next;

      node->next = insert->next;
      insert->next = node;
    }

    // non reversed tail
    while (head) {
      tail = tail->next = head;
      head = head->next;
    }
    return preHead.next;
  }
};
