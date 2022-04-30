#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
 public:
  std::vector<double> calcEquation(
      std::vector<std::vector<std::string>> &equations,
      std::vector<double> &values,
      std::vector<std::vector<std::string>> &queries) {
    std::unordered_map<std::string, std::unordered_map<std::string, double>>
        edges;

    for (size_t k = 0; k < values.size(); ++k) {
      const auto &e = equations[k];
      const auto &v = values[k];
      edges[e[0]][e[1]] = v;
      edges[e[1]][e[0]] = 1. / v;
    }

    std::vector<double> result;

    for (auto &query : queries) {
      auto &start = query[0];
      auto &end = query[1];
      std::queue<std::pair<std::string, double>> q;
      if (edges.count(start)) {
        q.push({start, 1});
      }
      std::unordered_set<std::string> visited;
      visited.insert(start);
      bool found = false;
      while (not q.empty()) {
        auto [vertex, value] = q.front();
        q.pop();
        if (vertex == end) {
          result.push_back(value);
          found = true;
          break;
        }
        for (auto &[nei, val] : edges[vertex]) {
          if (not visited.count(nei)) {
            q.push({nei, val * value});
            visited.insert(nei);
          }
        }
      }
      if (not found) {
        result.push_back(-1);
      }
    }
    return result;
  }
};
