#include <functional>
#include <optional>
#include <unordered_set>
#include <vector>

class Solution {
 public:
  int minTime(int, std::vector<std::vector<int>>& edges,
              std::vector<bool>& hasApple) {
    std::unordered_map<int, std::vector<int>> connections;

    for (auto const& edge : edges) {
      connections[edge[0]].push_back(edge[1]);
      connections[edge[1]].push_back(edge[0]);
    }

    std::unordered_set<int> visited;

    std::function<std::optional<int>(int)> dfs =
        [&](int vertex) -> std::optional<int> {
      if (not visited.insert(vertex).second) return std::nullopt;

      std::optional<int> Time = hasApple[static_cast<size_t>(vertex)]
                                    ? std::optional<int>(0)
                                    : std::nullopt;

      for (auto neighbour : connections[vertex]) {
        if (auto NeighbourTime = dfs(neighbour))
          Time = *NeighbourTime + 2 + Time.value_or(0);
      }

      return Time;
    };

    return dfs(0).value_or(0);
  }
};
