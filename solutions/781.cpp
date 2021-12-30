#include <unordered_map>
#include <vector>

class Solution {
 public:
  int numRabbits(std::vector<int>& answers) {
    std::unordered_map<int, int> counts;
    int result = 0;
    for (auto answer : answers) {
      if (answer) {
        ++counts[answer];
      } else {
        ++result;
      }
    }
    for (auto [value, count] : counts) {
      auto rabbits = count / (value + 1) * (value + 1);
      result += rabbits;

      if (count > rabbits) {
        result += value + 1;
      }
    }
    return result;
  }
};
