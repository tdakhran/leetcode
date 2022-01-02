#include <optional>
#include <string>
#include <vector>

class Solution {
 public:
  int shortestDistance(std::vector<std::string>& wordsDict, std::string word1,
                       std::string word2) {
    std::optional<size_t> pos1, pos2;
    int result = std::numeric_limits<int>::max();

    for (size_t pos = 0; pos < wordsDict.size(); ++pos) {
      if (wordsDict[pos] == word1) {
        pos1 = pos;
      } else if (wordsDict[pos] == word2) {
        pos2 = pos;
      }

      if (pos1 and pos2) {
        auto diff = *pos2 < *pos1 ? (*pos1 - *pos2) : (*pos2 - *pos1);
        result = std::min(result, static_cast<int>(diff));
      }
    }
    return result;
  }
};
