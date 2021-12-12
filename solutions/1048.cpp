#include <map>
#include <queue>
#include <unordered_set>
#include <vector>

class Solution {
  bool connected(std::string_view a, std::string_view b) {
    if (b.size() != a.size() + 1) {
      return false;
    }
    size_t lo = 0;
    size_t hi = b.size() - 1;

    while (lo < hi and a[lo] == b[lo]) {
      ++lo;
    }
    while (lo < hi and a[hi - 1] == b[hi]) {
      --hi;
    }
    return lo == hi;
  }

 public:
  int longestStrChain(std::vector<std::string> &words) {
    std::map<size_t, std::vector<std::string_view>> buckets;
    for (auto &word : words) {
      buckets[word.size()].push_back(word);
    }

    std::unordered_set<std::string_view> visited;

    std::queue<std::pair<std::string_view, int>> queue;

    int result = 0;
    for (const auto &[size, words] : buckets) {
      for (const auto &word : words) {
        if (visited.insert(word).second) {
          queue.push({word, 1});
        }
      }
      while (not queue.empty()) {
        auto [word, length] = queue.front();
        queue.pop();

        result = std::max(result, length);

        for (const auto &nei : buckets[word.size() + 1]) {
          if (connected(word, nei) and visited.insert(nei).second) {
            queue.push({nei, length + 1});
          }
        }
      }
    }

    return result;
  }
};
