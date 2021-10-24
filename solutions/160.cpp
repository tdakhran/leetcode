#include <utility>

class Solution {
  int len(ListNode *l) {
    int count = 0;
    while (l) {
      ++count;
      l = l->next;
    }
    return count;
  }

 public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    auto length = [](const ListNode *l) {
      std::size_t result = 0;
      for (; l; ++result, l = l->next) {
      }
      return result;
    };
    auto la = length(headA);
    auto lb = length(headB);
    if (la < lb) {
      std::swap(la, lb);
      std::swap(headA, headB);
    }
    for (; la > lb; headA = headA->next, --la) {
    }

    auto start = headA;
    while (headA) {
      if (headA != headB) {
        start = headA->next;
      }
      headA = headA->next;
      headB = headB->next;
    }
    return start;
  }
};
