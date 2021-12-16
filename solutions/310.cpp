#include <queue>
#include <unordered_set>
#include <vector>

class Solution {
 public:
  std::vector<int> findMinHeightTrees(size_t n,
                                      std::vector<std::vector<int>>& edges) {
    std::vector<std::unordered_set<size_t>> graph(n);
    for (const auto& e : edges) {
      auto from = static_cast<size_t>(e[0]);
      auto to = static_cast<size_t>(e[1]);
      graph[from].insert(to);
      graph[to].insert(from);
    }

    std::queue<size_t> q;
    for (size_t vertex = 0; vertex < n; ++vertex) {
      if (graph[vertex].size() == 1) {
        q.push(vertex);
      }
    }

    std::vector<int> result;
    while (not q.empty()) {
      auto qsize = q.size();
      result.clear();
      while (qsize--) {
        auto vertex = q.front();
        q.pop();
        result.push_back(static_cast<int>(vertex));

        for (auto nei : graph[vertex]) {
          graph[nei].erase(vertex);
          if (graph[nei].size() == 1) {
            q.push(nei);
          }
        }
      }
    }
    if (result.empty()) {
      result.push_back(0);
    }
    return result;
  }
};
