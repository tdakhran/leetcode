#include <queue>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  int minJumps(std::vector<int>& arr) {
    std::unordered_map<int, std::vector<size_t>> edges;
    for (size_t pos = 0; pos < arr.size(); ++pos) {
      edges[arr[pos]].push_back(pos);
    }

    std::queue<size_t> q;
    q.push(0);
    std::vector<int> visited(arr.size(), false);
    visited[0] = true;

    int steps = 0;

    while (not q.empty()) {
      auto qsize = q.size();
      while (qsize--) {
        auto v = q.front();
        q.pop();

        if (v == arr.size() - 1) {
          return steps;
        }

        if (v > 0 and not visited[v - 1]) {
          visited[v - 1] = true;
          q.push(v - 1);
        }

        if (not visited[v + 1]) {
          visited[v + 1] = true;
          q.push(v + 1);
        }

        for (auto e : edges[arr[v]]) {
          if (not visited[e]) {
            visited[e] = true;
            q.push(e);
          }
        }
        edges[arr[v]].clear();
      }
      ++steps;
    }

    return -1;
  }
};
