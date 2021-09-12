#include <algorithm>
#include <limits>
#include <queue>
#include <utility>
#include <vector>

class Solution {
  struct Edge {
    unsigned src;
    unsigned dst;
    int weight;
    int src_cov;
    int dst_cov;
  };

 public:
  int reachableNodes(std::vector<std::vector<int>> &edges, int maxMoves,
                     size_t n) {
    std::vector<Edge> edge_holder;
    edge_holder.reserve(n);

    std::vector<std::vector<size_t>> edge(n);
    for (const auto &e : edges) {
      edge[static_cast<size_t>(e[0])].push_back(edge_holder.size());
      edge[static_cast<size_t>(e[1])].push_back(edge_holder.size());
      edge_holder.push_back({static_cast<unsigned>(e[0]),
                             static_cast<unsigned>(e[1]), e[2], 0, 0});
    }

    std::priority_queue<std::pair<unsigned, int>,
                        std::vector<std::pair<unsigned, int>>,
                        std::greater<std::pair<unsigned, int>>>
        pq;

    std::vector<int> distances(n, std::numeric_limits<int>::max());

    pq.push({0, 0});
    distances[0] = 0;

    while (not pq.empty()) {
      auto [vertex, dist] = pq.top();
      pq.pop();

      for (auto edge_holder_id : edge[vertex]) {
        auto &e = edge_holder[edge_holder_id];
        auto nei_dist = dist + e.weight + 1;
        auto nei = e.src != vertex ? e.src : e.dst;
        if (nei_dist < distances[nei] and nei_dist <= maxMoves) {
          distances[nei] = nei_dist;
          pq.push({nei, nei_dist});
        }
        auto &coverage = e.src != vertex ? e.src_cov : e.dst_cov;
        coverage = std::max(coverage, maxMoves - dist);
      }
    }

    int result = static_cast<int>(
        std::count_if(begin(distances), end(distances),
                      [maxMoves](int dist) { return dist <= maxMoves; }));

    for (const auto &e : edge_holder) {
      result += std::min(e.src_cov + e.dst_cov, e.weight);
    }

    return result;
  }
};
