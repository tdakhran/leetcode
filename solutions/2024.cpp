#include <queue>
#include <string>

class Solution {
 public:
  int maxConsecutiveAnswers(std::string answerKey, size_t k) {
    int result = 0;
    for (auto target : {'T', 'F'}) {
      for (size_t right = 0, left = 0, capacity = k; right < answerKey.size();
           ++right) {
        while (answerKey[right] != target and !capacity) {
          capacity += (answerKey[left++] != target);
        }
        capacity -= (answerKey[right] != target);
        result = std::max(result, static_cast<int>(right - left + 1));
      }
    }

    return result;
  }
};
