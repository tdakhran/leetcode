#include <vector>

class Solution {
 public:
  std::vector<ListNode *> splitListToParts(ListNode *head, int k) {
    int size = 0;
    auto it = head;
    while (it) {
      ++size;
      it = it->next;
    }
    int chunk_size = size / k;
    int extra_one = size % k;

    std::vector<ListNode *> result;

    while (result.size() < static_cast<size_t>(k)) {
      result.push_back(head);
      int current_size = chunk_size + (extra_one > 0) - 1;
      --extra_one;
      while (current_size-- > 0) {
        head = head->next;
      }
      if (head) {
        auto next = head->next;
        head->next = nullptr;
        head = next;
      }
    }
    return result;
  }
};
