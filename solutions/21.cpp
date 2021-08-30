class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode preHead(0);
    auto tail = &preHead;

    while (l1 and l2) {
      auto& l = (l1->val < l2->val) ? l1 : l2;
      tail = tail->next = l;
      l = l->next;
    }
    tail->next = l1 ? l1 : l2;
    return preHead.next;
  }
};
