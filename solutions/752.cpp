#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

class Solution {
 public:
  int openLock(std::vector<std::string>& deadends, std::string target) {
    const std::string initial_state("0000");
    std::queue<std::string> bfs_queue;

    std::unordered_set<std::string> visited(begin(deadends), end(deadends));
    if (visited.insert(initial_state).second) {
      bfs_queue.push(initial_state);
    }

    for (int turns = 0; not bfs_queue.empty(); ++turns) {
      auto bfs_queue_size = bfs_queue.size();
      while (bfs_queue_size--) {
        auto state = bfs_queue.front();
        bfs_queue.pop();

        if (state == target) {
          return turns;
        }

        for (auto& cell : state) {
          auto saved_cell = cell;

          for (auto delta : {1, -2}) {
            cell = ((cell + 10 - '0' + delta) % 10) + '0';
            if (visited.insert(state).second) {
              bfs_queue.push(state);
            }
          }
          cell = saved_cell;
        }
      }
    }

    return -1;
  }
};
