#include <vector>

class Solution {
 public:
  std::vector<int> getRow(size_t rowIndex) {
    std::vector<int> result(rowIndex + 1, 1);
    for (size_t row_id = 2; row_id <= rowIndex; ++row_id) {
      int tmp = result[0];
      for (size_t i = 1; i + 1 < row_id + 1; ++i) {
        auto v = result[i];
        result[i] += tmp;
        tmp = v;
      }
    }
    return result;
  }
};
