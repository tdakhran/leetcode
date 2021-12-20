#include <algorithm>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> minimumAbsDifference(std::vector<int>& arr) {
    std::sort(begin(arr), end(arr));
    std::vector<std::vector<int>> result;
    int64_t max_diff = std::numeric_limits<int64_t>::max();

    for (size_t k = 1; k < arr.size(); ++k) {
      if (auto diff = abs(arr[k] - arr[k - 1]); diff < max_diff) {
        result = {{arr[k - 1], arr[k]}};
        max_diff = diff;
      } else if (diff == max_diff) {
        result.push_back({arr[k - 1], arr[k]});
      }
    }
    return result;
  }
};
