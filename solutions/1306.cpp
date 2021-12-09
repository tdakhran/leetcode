#include <unordered_map>
#include <vector>

class Solution {
  std::unordered_map<int, bool> cache;

 public:
  bool canReach(std::vector<int>& arr, int start) {
    if (start < 0 or start >= static_cast<int>(arr.size())) {
      return false;
    }
    auto value = arr[static_cast<size_t>(start)];
    if (value == 0) {
      return true;
    }
    if (cache.count(start)) {
      return cache[start];
    }
    cache[start] = false;
    return cache[start] =
               canReach(arr, start - value) or canReach(arr, start + value);
  }
};
