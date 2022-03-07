#include <numeric>
#include <vector>

class Solution {
 public:
  int numOfSubarrays(std::vector<int>& arr, int k, int threshold) {
    int sum = std::accumulate(begin(arr), next(begin(arr), k), 0);

    int result = (sum / k) >= threshold;

    for (size_t pos = static_cast<size_t>(k); pos < arr.size(); ++pos) {
      sum += arr[pos] - arr[pos - static_cast<size_t>(k)];
      result += (sum / k) >= threshold;
    }
    return result;
  }
};
