#include <functional>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> allPathsSourceTarget(
      std::vector<std::vector<int>>& graph) {
    std::vector<std::vector<int>> result;
    std::vector<int> current_path{0};

    std::function<void(int)> dfs = [&dfs, &result, &current_path,
                                    &graph](size_t vertex) {
      if (vertex == graph.size() - 1) {
        result.push_back(current_path);
        return;
      }
      for (auto nei : graph[vertex]) {
        current_path.push_back(nei);
        dfs(nei);
        current_path.pop_back();
      }
    };

    dfs(0);
    return result;
  }
};
