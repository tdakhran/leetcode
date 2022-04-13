#include <string>
#include <vector>

class Solution {
 public:
  int minCost(std::string colors, std::vector<int>& neededTime) {
    int chunk_time = neededTime.front();
    int max_time = neededTime.front();
    int result = 0;

    for (size_t pos = 1; pos < colors.size(); ++pos) {
      if (colors[pos - 1] != colors[pos]) {
        result += chunk_time - max_time;
        chunk_time = max_time = 0;
      }
      chunk_time += neededTime[pos];
      max_time = std::max(max_time, neededTime[pos]);
    }
    return result + chunk_time - max_time;
  }
};
