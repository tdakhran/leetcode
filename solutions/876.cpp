class Solution {
 public:
  ListNode* middleNode(ListNode* head) {
    auto slow = head;
    auto fast = head;
    while (slow and fast) {
      fast = fast->next;
      if (fast) {
        fast = fast->next;
        slow = slow->next;
      }
    }
    return slow;
  }
};
