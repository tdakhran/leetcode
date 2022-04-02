#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

/*
class Employee {
 public:
  int id;
  int importance;
  std::vector<int> subordinates;
};
*/

class Solution {
 public:
  int getImportance(std::vector<Employee*> employees, int id) {
    std::unordered_map<int, const Employee*> id2e;
    for (auto e : employees) {
      id2e[e->id] = e;
    }

    std::unordered_set<int> visited({id});
    std::queue<int> queue({id});

    int total_importance = 0;
    while (not queue.empty()) {
      auto e = id2e[queue.front()];
      queue.pop();

      total_importance += e->importance;
      for (const auto nei : e->subordinates) {
        if (visited.insert(nei).second) {
          queue.push(nei);
        }
      }
    }
    return total_importance;
  }
};
