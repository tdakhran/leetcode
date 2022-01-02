#include <string>
#include <vector>

class Solution {
 public:
  std::vector<std::string> generatePossibleNextMoves(std::string currentState) {
    std::vector<std::string> result;

    for (size_t pos = 1; pos < currentState.size(); ++pos) {
      if (currentState[pos - 1] == currentState[pos] and
          currentState[pos] == '+') {
        currentState[pos - 1] = currentState[pos] = '-';
        result.push_back(currentState);
        currentState[pos - 1] = currentState[pos] = '+';
      }
    }
    return result;
  }
};
