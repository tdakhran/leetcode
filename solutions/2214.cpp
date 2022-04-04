#include <vector>

class Solution {
 public:
  long long minimumHealth(std::vector<int>& damage, int armor) {
    long long health = 1;
    int max_damage = 0;
    for (auto d : damage) {
      health += d;
      max_damage = std::max(max_damage, d);
    }

    return health - std::min(armor, max_damage);
  }
};
