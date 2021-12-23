#include <vector>

class Solution {
 public:
  std::vector<int> findOrder(size_t numCourses,
                             std::vector<std::vector<int>>& prerequisites) {
    std::vector<std::vector<int>> edges(numCourses);
    std::vector<int> incoming_count(numCourses);

    for (const auto& p : prerequisites) {
      edges[static_cast<size_t>(p[1])].push_back(p[0]);
      ++incoming_count[static_cast<size_t>(p[0])];
    }

    std::vector<int> result;

    for (size_t vertex = 0; vertex < numCourses; ++vertex) {
      if (auto& count = incoming_count[vertex]; count == 0) {
        result.push_back(static_cast<int>(vertex));
        --count;
      }
    }

    for (size_t start = 0; start < result.size();) {
      auto end = result.size();
      while (start < end) {
        for (auto e : edges[static_cast<size_t>(result[start])]) {
          if (auto& count = incoming_count[static_cast<size_t>(e)];
              --count == 0) {
            result.push_back(e);
            --count;
          }
        }
        ++start;
      }
    }

    return result.size() == numCourses ? result : std::vector<int>();
  }
};
