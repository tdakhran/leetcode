#include <vector>

class Solution {
 public:
  bool canPlaceFlowers(std::vector<int>& flowerbed, int n) {
    flowerbed.push_back(0);
    flowerbed.push_back(1);
    int prev = -2;
    int slots = 0;
    for (size_t pos = 0; slots < n and pos < flowerbed.size(); ++pos) {
      if (flowerbed[pos] == 1) {
        int slot = static_cast<int>(pos) - prev - 2;
        slots += slot / 2;
        prev += slot + 2;
      }
    }
    return slots >= n;
  }
};
