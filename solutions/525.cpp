#include <unordered_map>
#include <vector>

class Solution {
 public:
  int findMaxLength(std::vector<int>& nums) {
    int result = 0;
    std::unordered_map<int, int> s2pos;

    s2pos[0] = -1;

    int acc = 0;

    for (size_t k = 0; k < nums.size(); ++k) {
      acc += nums[k] == 1 ? 1 : -1;
      if (auto it = s2pos.find(acc); it == end(s2pos)) {
        s2pos[acc] = static_cast<int>(k);
      } else {
        result = std::max(result, static_cast<int>(k) - it->second);
      }
    }

    return result;
  }
};
