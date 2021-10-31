#include <algorithm>
#include <queue>
#include <vector>

class Solution {
 public:
  bool canVisitAllRooms(std::vector<std::vector<int>>& rooms) {
    auto n = rooms.size();

    std::vector<bool> visited(n, false);
    visited[0] = true;

    std::queue<int> q;
    q.push(0);

    do {
      auto room = static_cast<size_t>(q.front());
      q.pop();

      for (const auto& key : rooms[room]) {
        if (not visited[static_cast<size_t>(key)]) {
          visited[static_cast<size_t>(key)] = true;
          q.push(key);
        }
      }
    } while (not q.empty());

    return std::all_of(begin(visited), end(visited), [](auto v) { return v; });
  }
};
