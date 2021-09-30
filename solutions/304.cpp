#include <numeric>
#include <vector>

class NumMatrix {
 public:
  NumMatrix(std::vector<std::vector<int>>& matrix) : ps(std::move(matrix)) {
    std::partial_sum(begin(ps.front()), end(ps.front()), begin(ps.front()));
    for (size_t row = 1; row < ps.size(); ++row) {
      for (struct {
             unsigned col = 0;
             int row_sum = 0;
           } i;
           i.col < ps.front().size(); ++i.col) {
        i.row_sum += ps[row][i.col];
        ps[row][i.col] = i.row_sum + ps[row - 1][i.col];
      }
    }
  }

  int sumRegion(size_t row1, size_t col1, size_t row2, size_t col2) {
    return ps[row2][col2] - (col1 ? ps[row2][col1 - 1] : 0) -
           (row1 ? ps[row1 - 1][col2] : 0) +
           ((col1 and row1) ? ps[row1 - 1][col1 - 1] : 0);
  }

 private:
  std::vector<std::vector<int>> ps;
};
