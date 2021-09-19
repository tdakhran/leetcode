class Solution {
 public:
  ListNode* deleteDuplicates(ListNode* head) {
    ListNode preHead(0, head);
    auto it = &preHead;
    while (it->next and it->next->next) {
      if (it->next->val == it->next->next->val) {
        auto val = it->next->val;
        while (it->next and it->next->val == val) {
          it->next = it->next->next;
        }
      } else {
        it = it->next;
      }
    }
    return preHead.next;
  }
};
