class Solution {
 public:
  ListNode* middleNode(ListNode* head) {
    auto middle = head;
    while (head and head->next) {
      middle = middle->next;
      head = head->next->next;
    }
    return middle;
  }
};
