#include <optional>
#include <vector>

class Solution {
 public:
  std::vector<int> nodesBetweenCriticalPoints(ListNode *head) {
    int prev_val = head->val;
    std::optional<int> first_pos;
    std::optional<int> prev_pos;
    int min_distance = std::numeric_limits<int>::max();

    auto critical_point = [](int a, int b, int c) {
      return (a < b and b > c) or (a > b and b < c);
    };

    int pos = 0;
    while (head and head->next) {
      if (critical_point(prev_val, head->val, head->next->val)) {
        if (first_pos) {
          min_distance = std::min(min_distance, pos - *prev_pos);
        } else {
          first_pos = pos;
        }
        prev_pos = pos;
      }
      prev_val = head->val;
      head = head->next;
      ++pos;
    }

    if (first_pos and prev_pos and *first_pos != *prev_pos) {
      return {min_distance, *prev_pos - *first_pos};
    }

    return {-1, -1};
  }
};
