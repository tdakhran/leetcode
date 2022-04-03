class Solution {
 public:
  ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
    ListNode preHead;
    auto tail = &preHead;

    int count = b - a + 1;
    while (a--) {
      tail = tail->next = list1;
      list1 = list1->next;
    }
    while (count--) {
      list1 = list1->next;
    }
    while (list2) {
      tail = tail->next = list2;
      list2 = list2->next;
    }
    while (list1) {
      tail = tail->next = list1;
      list1 = list1->next;
    }

    return preHead.next;
  }
};
