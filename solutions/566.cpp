#include <vector>

class Solution {
  class Iterator2D {
   public:
    explicit Iterator2D(std::vector<std::vector<int>> &data) : mat(data) {}

    operator bool() const { return row < mat.size(); }

    Iterator2D operator++(int) {
      Iterator2D copy = *this;
      if (++col >= mat.front().size()) {
        col = 0;
        ++row;
      }
      return copy;
    }

    int &operator*() { return mat[row][col]; }

   private:
    size_t row = 0;
    size_t col = 0;
    std::vector<std::vector<int>> &mat;
  };

 public:
  std::vector<std::vector<int>> matrixReshape(
      std::vector<std::vector<int>> &mat, size_t r, size_t c) {
    if (mat.size() * mat.front().size() != r * c) {
      return mat;
    }
    auto result = std::vector<std::vector<int>>(r, std::vector<int>(c));

    auto src_it = Iterator2D(mat);
    auto dst_it = Iterator2D(result);
    while (src_it) {
      *dst_it++ = *src_it++;
    }

    return result;
  }
};
