class Solution {
 public:
  ListNode *oddEvenList(ListNode *head) {
    ListNode odd, even;
    auto odd_tail = &odd;
    auto even_tail = &even;

    for (bool is_odd = true; head; is_odd = !is_odd, head = head->next) {
      auto &tail = is_odd ? odd_tail : even_tail;
      tail = tail->next = head;
    }

    odd_tail->next = even.next;
    even_tail->next = nullptr;
    return odd.next;
  }
};
