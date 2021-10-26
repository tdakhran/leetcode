class Solution {
 public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode preHead;
    auto tail = &preHead;

    while (head) {
      int len = 0;
      for (auto it = head; it and len < k; it = it->next, ++len) {
      }

      if (len < k) {
        tail->next = head;
        break;
      }

      auto new_tail = head;

      ListNode* rev_k = nullptr;
      while (len--) {
        auto tmp = head;
        head = head->next;
        tmp->next = rev_k;
        rev_k = tmp;
      }
      tail->next = rev_k;

      tail = new_tail;
    }
    return preHead.next;
  }
};
