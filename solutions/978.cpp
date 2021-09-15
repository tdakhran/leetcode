#include <vector>

class Solution {
 public:
  int maxTurbulenceSize(std::vector<int>& A) {
    int l = 1;
    int g = 1;
    int result = 1;
    for (size_t k = 1; k < A.size(); ++k) {
      if (A[k] > A[k - 1]) {
        g = l + 1;
        l = 1;
      } else if (A[k] < A[k - 1]) {
        l = g + 1;
        g = 1;
      } else {
        l = g = 1;
      }
      result = std::max(result, std::max(l, g));
    }
    return result;
  }
};
