#include <functional>
#include <queue>
#include <vector>

class Solution {
 public:
  ListNode *mergeKLists(std::vector<ListNode *> &lists) {
    std::priority_queue<ListNode *, std::vector<ListNode *>,
                        std::function<bool(const ListNode *, const ListNode *)>>
        pq([](const ListNode *a, const ListNode *b) {
          return a->val > b->val;
        });
    ListNode result(0);
    ListNode *tail = &result;

    for (auto node : lists) {
      if (node) {
        pq.push(node);
      }
    }

    while (not pq.empty()) {
      auto node = pq.top();
      pq.pop();

      tail->next = node;
      tail = tail->next;
      if (node->next) {
        pq.push(node->next);
      }
    }

    return result.next;
  }
};
