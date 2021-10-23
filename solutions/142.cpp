class Solution {
 public:
  ListNode *detectCycle(ListNode *head) {
    auto slow = head;
    auto fast = head;
    while (slow and slow->next and fast->next and fast->next->next) {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast) {
        fast = head;
        while (slow != fast) {
          slow = slow->next;
          fast = fast->next;
        }
        return slow;
      }
    }
    return nullptr;
  }
};
