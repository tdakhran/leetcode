class Solution {
 public:
  ListNode* plusOne(ListNode* head) {
    ListNode* right_most_non_9 = nullptr;
    for (auto it = head; it; it = it->next) {
      if (it->val != 9) {
        right_most_non_9 = it;
      }
    }

    if (!right_most_non_9) {
      head = right_most_non_9 = new ListNode(0, head);
    }

    ++right_most_non_9->val;
    right_most_non_9 = right_most_non_9->next;

    while (right_most_non_9) {
      right_most_non_9->val = 0;
      right_most_non_9 = right_most_non_9->next;
    }

    return head;
  }
};
