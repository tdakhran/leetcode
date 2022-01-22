#include <vector>

class Solution {
 public:
  bool winnerSquareGame(int n) {
    std::vector<bool> states(static_cast<size_t>(n) + 1, false);

    for (size_t i = 0; i < states.size(); ++i) {
      if (states[i] == false) {
        for (size_t k = 1; k * k < states.size() && i + k * k < states.size();
             ++k) {
          states[i + k * k] = true;
        }
      }
    }

    return states.back();
  }
};
