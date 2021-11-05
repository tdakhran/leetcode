#include <unordered_set>
#include <vector>

class Solution {
 public:
  int lenLongestFibSubseq(std::vector<int>& arr) {
    std::unordered_set<int> nums(begin(arr), end(arr));
    int result = 0;
    for (size_t i = 0; i < arr.size(); ++i) {
      for (size_t j = i + 1; j < arr.size(); ++j) {
        for (int count = 2, pprev = arr[i], prev = arr[j],
                 cur = arr[i] + arr[j];
             nums.count(cur);
             cur = pprev + prev, pprev = prev, prev = cur, ++count) {
          result = std::max(result, count);
        }
      }
    }
    return result;
  }
};
