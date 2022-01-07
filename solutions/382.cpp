#include <random>

class Solution {
  ListNode *head_ = nullptr;

 public:
  Solution(ListNode *head) : head_(head) {}

  int getRandom() {
    int res = 0, len = 1;
    ListNode *v = head_;
    while (v) {
      if (rand() % len == 0) {
        res = v->val;
      }
      len++;
      v = v->next;
    }
    return res;
  }
};
