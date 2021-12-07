#include <string>
#include <vector>

class Solution {
 public:
  std::string stringShift(std::string s, std::vector<std::vector<int>>& shift) {
    int total_shift = 0;
    for (const auto& sh : shift) {
      total_shift += sh[0] ? sh[1] : -sh[1];
    }
    size_t shift_point =
        (1000 * s.size() - static_cast<size_t>(total_shift)) % s.size();
    return s.substr(shift_point) + s.substr(0, shift_point);
  }
};
