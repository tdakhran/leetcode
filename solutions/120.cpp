#include <algorithm>
#include <vector>

class Solution {
 public:
  int minimumTotal(std::vector<std::vector<int>>& triangle) {
    for (size_t r = 1; r < triangle.size(); ++r) {
      triangle[r].front() += triangle[r - 1].front();
      for (size_t c = 1; c + 1 < triangle[r].size(); ++c) {
        triangle[r][c] += std::min(triangle[r - 1][c], triangle[r - 1][c - 1]);
      }
      triangle[r].back() += triangle[r - 1].back();
    }
    return *std::min_element(begin(triangle.back()), end(triangle.back()));
  }
};
