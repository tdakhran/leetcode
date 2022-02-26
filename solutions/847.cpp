#include <queue>
#include <vector>

class Solution {
 public:
  int shortestPathLength(std::vector<std::vector<int>>& graph) {
    if (graph.size() == 1) {
      return 0;
    }

    unsigned target_mask = (1 << graph.size()) - 1;
    auto visited = std::vector<std::vector<bool>>(
        graph.size(), std::vector<bool>(target_mask));

    std::queue<std::pair<unsigned, unsigned>> q;
    for (unsigned i = 0; i < graph.size(); ++i) {
      q.push({i, (1 << i)});
      visited[i][1 << i] = true;
    }

    for (int steps = 1; not q.empty(); ++steps) {
      auto qsize = q.size();
      while (qsize--) {
        auto [v, mask] = q.front();
        q.pop();

        for (auto nei : graph[v]) {
          auto next_mask = mask | (1 << nei);
          if (next_mask == target_mask) {
            return steps;
          }

          if (!visited[static_cast<size_t>(nei)][next_mask]) {
            visited[static_cast<size_t>(nei)][next_mask] = true;
            q.push({nei, next_mask});
          }
        }
      }
    }

    return -1;
  }
};
