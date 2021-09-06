#include <string>
#include <vector>

class Solution {
 public:
  char slowestKey(std::vector<int>& releaseTimes, std::string keysPressed) {
    char result = keysPressed.front();
    int longest = releaseTimes.front();
    for (size_t pos = 1; pos < keysPressed.size(); ++pos) {
      if (auto delta = releaseTimes[pos] - releaseTimes[pos - 1];
          delta >= longest) {
        result = (delta == longest) ? std::max(keysPressed[pos], result)
                                    : keysPressed[pos];
        longest = delta;
      }
    }
    return result;
  }
};
