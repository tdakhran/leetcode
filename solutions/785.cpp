#include <queue>
#include <vector>

class Solution {
 public:
  bool isBipartite(std::vector<std::vector<int>>& graph) {
    std::vector<char> type(graph.size());

    std::queue<size_t> q;
    for (size_t v = 0; v < graph.size(); ++v) {
      if (not type[v]) {
        q.push(v);
        type[v] = 1;
      }

      while (not q.empty()) {
        auto u = q.front();
        q.pop();

        for (auto nei : graph[u]) {
          if (auto nei_u = static_cast<size_t>(nei); type[nei_u] == type[u]) {
            return false;
          } else if (not type[nei_u]) {
            q.push(nei_u);
            type[nei_u] = -type[u];
          }
        }
      }
    }
    return true;
  }
};
