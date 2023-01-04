#include <unordered_map>
#include <vector>

class Solution {
 public:
  int minimumRounds(std::vector<int> &tasks) {
    std::unordered_map<int, std::size_t> counts;
    for (auto const &task : tasks) ++counts[task];

    int rounds = 0;
    for (auto const &[_, count] : counts)
      if (count > 1)
        rounds += count / 3 + ((count % 3) != 0);
      else
        return -1;

    return rounds;
  }
};
