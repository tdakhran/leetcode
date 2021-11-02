#include <array>
#include <map>
#include <numeric>
#include <unordered_set>
#include <vector>

class Solution {
 public:
  int maxPoints(std::vector<std::vector<int>>& points) {
    std::map<std::array<int, 3>, std::unordered_set<size_t>> m;
    int result = 0;
    for (size_t i = 1; i < points.size(); ++i) {
      for (size_t j = 0; j < i; ++j) {
        std::array<int, 3> line{
            points[i][0] - points[j][0],
            points[i][1] - points[j][1],
            points[i][0] * points[j][1] - points[j][0] * points[i][1],
        };

        if (line[0] < 0) {
          for (auto& e : line) {
            e *= -1;
          }
        }
        auto gcd = std::gcd(std::gcd(line[0], line[1]), line[2]);
        for (auto& e : line) {
          e /= gcd;
        }

        auto& line_points = m[line];
        line_points.insert(i);
        line_points.insert(j);
        result = std::max(result, static_cast<int>(line_points.size()));
      }
    }
    return std::max(1, result);
  }
};
