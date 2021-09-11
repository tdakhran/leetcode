class Solution {
 public:
  ListNode* deleteDuplicates(ListNode* head) {
    auto it = head;
    while (it) {
      if (it->next and it->next->val == it->val) {
        it->next = it->next->next;
      } else {
        it = it->next;
      }
    }
    return head;
  }
};
