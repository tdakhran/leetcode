#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> generate(size_t numRows) {
    std::vector<std::vector<int>> result;
    for (size_t row_id = 1; row_id <= numRows; ++row_id) {
      auto row = std::vector<int>(row_id);
      row.front() = row.back() = 1;
      for (size_t pos = 1; pos + 1 < row_id; ++pos) {
        row[pos] = result.back()[pos - 1] + result.back()[pos];
      }
      result.push_back(std::move(row));
    }
    return result;
  }
};
