class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int carry = 0;
    ListNode preHead;
    ListNode* tail = &preHead;
    while (l1 or l2 or carry) {
      if (l1) {
        carry += l1->val;
        l1 = l1->next;
      }
      if (l2) {
        carry += l2->val;
        l2 = l2->next;
      }
      tail = tail->next = new ListNode(carry % 10);
      carry /= 10;
    }
    return preHead.next;
  }
};
