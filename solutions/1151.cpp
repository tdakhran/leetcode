#include <numeric>
#include <vector>

class Solution {
 public:
  int minSwaps(std::vector<int>& data) {
    int ones = std::accumulate(begin(data), end(data), 0);
    int current_sum = 0;
    for (size_t pos = 0; pos < static_cast<size_t>(ones); ++pos) {
      current_sum += data[pos];
    }
    int result = ones - current_sum;
    for (size_t pos = static_cast<size_t>(ones); pos < data.size(); ++pos) {
      current_sum += data[pos] - data[pos - static_cast<size_t>(ones)];
      result = std::min(result, ones - current_sum);
    }
    return result;
  }
};
