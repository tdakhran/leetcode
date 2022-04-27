#include <algorithm>
#include <queue>
#include <string>
#include <vector>

class Solution {
 public:
  std::string smallestStringWithSwaps(std::string s,
                                      std::vector<std::vector<int>>& pairs) {
    std::vector<bool> visited(s.size());
    std::vector<std::vector<size_t>> nei(s.size());
    for (const auto& p : pairs) {
      size_t from = static_cast<size_t>(p[0]);
      size_t to = static_cast<size_t>(p[1]);
      nei[from].push_back(to);
      nei[to].push_back(from);
    }

    std::queue<size_t> bfs_queue;
    for (size_t p = 0; p < s.size(); ++p) {
      std::string chunk;
      std::vector<size_t> chunk_idx;

      if (not visited[p]) {
        bfs_queue.push(p);
        chunk_idx.push_back(p);
        visited[p] = true;
        chunk.push_back(s[p]);
      }

      while (not bfs_queue.empty()) {
        auto i = bfs_queue.front();
        bfs_queue.pop();

        for (auto n : nei[i]) {
          if (not visited[n]) {
            bfs_queue.push(n);
            visited[n] = true;
            chunk_idx.push_back(n);
            chunk.push_back(s[n]);
          }
        }
      }
      std::sort(begin(chunk), end(chunk));
      std::sort(begin(chunk_idx), end(chunk_idx));
      for (size_t i = 0; i < chunk.size(); ++i) {
        s[chunk_idx[i]] = chunk[i];
      }
    }
    return s;
  }
};
