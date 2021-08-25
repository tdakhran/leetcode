class Solution {
 public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    auto back = head;
    auto front = head;
    for (int i = 0; i < n; ++i) {
      if (!front->next) {
        return head->next;
      }
      front = front->next;
    }

    while (front->next) {
      back = back->next;
      front = front->next;
    }
    if (back->next) {
      back->next = back->next->next;
    }
    return head;
  }
};
