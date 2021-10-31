#include <vector>

class Solution {
 public:
  std::vector<int> findSmallestSetOfVertices(
      int n, std::vector<std::vector<int>>& edges) {
    std::vector<bool> vertices(static_cast<size_t>(n));
    std::vector<bool> incoming(static_cast<size_t>(n));

    for (const auto& edge : edges) {
      vertices[static_cast<size_t>(edge[0])] = true;
      incoming[static_cast<size_t>(edge[1])] = true;
    }

    std::vector<int> result;
    for (int vertex = 0; vertex < n; ++vertex) {
      if (not incoming[static_cast<size_t>(vertex)]) {
        result.push_back(vertex);
      }
    }
    return result;
  }
};
