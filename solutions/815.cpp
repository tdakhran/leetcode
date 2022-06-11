#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
 public:
  int numBusesToDestination(std::vector<std::vector<int>>& routes, int source,
                            int target) {
    std::unordered_map<int, std::unordered_set<size_t>> stop2bus;
    for (size_t bus = 0; bus < routes.size(); ++bus) {
      for (auto stop : routes[bus]) {
        stop2bus[stop].insert(bus);
      }
    }

    std::queue<int> q{{source}};
    std::unordered_set<int> visited_stops{source};
    std::unordered_set<size_t> visited_buses;

    for (int buses = 0; not q.empty(); ++buses) {
      auto qsize = q.size();
      while (qsize--) {
        auto cur_stop = q.front();
        q.pop();

        if (cur_stop == target) {
          return buses;
        }

        for (auto bus : stop2bus[cur_stop]) {
          if (visited_buses.insert(bus).second) {
            for (auto stop : routes[bus]) {
              if (visited_stops.insert(stop).second) {
                q.push(stop);
              }
            }
          }
        }
      }
    }

    return -1;
  }
};
