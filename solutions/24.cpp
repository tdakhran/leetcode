class Solution {
 public:
  ListNode* swapPairs(ListNode* head) {
    ListNode preHead(0, head);
    for (auto n0 = &preHead; n0->next and n0->next->next; n0 = n0->next->next) {
      auto n1 = n0->next;
      auto n2 = n0->next->next;
      auto n3 = n0->next->next->next;

      n0->next = n2;
      n2->next = n1;
      n1->next = n3;
    }
    return preHead.next;
  }
};
