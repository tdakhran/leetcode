#include <functional>
#include <vector>

class Solution {
 public:
  int findCircleNum(std::vector<std::vector<int>>& isConnected) {
    std::vector<bool> visited(isConnected.size());

    std::function<bool(size_t)> dfs = [&dfs, &isConnected,
                                       &visited](size_t id) {
      if (visited[id]) {
        return false;
      }
      visited[id] = true;

      for (size_t nei = 0; nei < visited.size(); ++nei) {
        if (isConnected[id][nei]) {
          dfs(nei);
        }
      }

      return true;
    };

    int result = 0;
    for (size_t id = 0; id < visited.size(); ++id) {
      result += dfs(id);
    }
    return result;
  }
};
