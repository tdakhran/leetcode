#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
 public:
  int longestConsecutive(std::vector<int>& nums) {
    struct Bucket {
      int start, end;
    };

    std::unordered_map<int, Bucket> start2bucket, end2bucket;
    std::unordered_set<int> seen;

    int result = 0;
    for (auto n : nums) {
      if (!seen.insert(n).second) {
        continue;
      }
      auto s = start2bucket.find(n + 1);
      auto e = end2bucket.find(n - 1);
      Bucket b{n, n};
      if (s != end(start2bucket) and e != end(end2bucket)) {
        b = {e->second.start, s->second.end};
        start2bucket.erase(s);
        end2bucket.erase(e);
      } else if (s != end(start2bucket)) {
        b.end = s->second.end;
        start2bucket.erase(s);
      } else if (e != end(start2bucket)) {
        b.start = e->second.start;
        end2bucket.erase(e);
      }
      result = std::max(result, b.end - b.start + 1);
      start2bucket[b.start] = end2bucket[b.end] = b;
    }
    return result;
  }
};
