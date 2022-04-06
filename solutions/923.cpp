#include <array>
#include <vector>

class Solution {
 public:
  int threeSumMulti(std::vector<int>& arr, int target) {
    constexpr int modulo = 1'000'000'007;
    int result = 0;
    for (size_t i = 0; i < arr.size(); ++i) {
      std::array<int, 101> freq{0};
      for (size_t k = i + 1; k < arr.size(); ++k) {
        size_t residual = static_cast<size_t>(target - arr[i] - arr[k]);
        if (residual <= 100) {
          result = (result + freq[residual]) % modulo;
        }
        ++freq[static_cast<size_t>(arr[k])];
      }
    }
    return result;
  }
};
