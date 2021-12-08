#include <queue>
#include <vector>

class Solution {
 public:
  int depthSumInverse(std::vector<NestedInteger> &nestedList) {
    std::vector<std::pair<int, int>> values;
    std::queue<const NestedInteger *> q;

    for (const auto &ni : nestedList) {
      q.push(&ni);
    }

    int max_depth = 1;
    for (; not q.empty(); ++max_depth) {
      auto queue_size = q.size();
      while (queue_size--) {
        auto ni = q.front();
        q.pop();
        if (ni->isInteger()) {
          values.push_back({ni->getInteger(), max_depth});
          continue;
        }
        for (const auto &ch_ni : ni->getList()) {
          q.push(&ch_ni);
        }
      }
    }

    int result = 0;
    for (const auto &[value, depth] : values) {
      result += value * (max_depth - depth);
    }
    return result;
  }
};
