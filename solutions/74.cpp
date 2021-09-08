#include <algorithm>
#include <vector>

class Solution {
  class Iterator2D {
   public:
    typedef std::random_access_iterator_tag iterator_category;
    typedef int value_type;
    typedef int difference_type;
    typedef int* pointer;
    typedef int& reference;
    explicit Iterator2D(std::vector<std::vector<int>>& data) : mat(data) {}

    Iterator2D end() const {
      Iterator2D copy = *this;
      copy.pos = static_cast<int64_t>(mat.size() * mat.front().size());
      return copy;
    }

    bool operator!=(const Iterator2D& other) const { return pos != other.pos; }

    int operator*() const {
      return mat[static_cast<size_t>(pos) / mat.front().size()]
                [static_cast<size_t>(pos) % mat.front().size()];
    }

    int64_t operator-(const Iterator2D& other) const { return pos - other.pos; }
    void operator++() { ++pos; }
    void operator--() { --pos; }

    void operator+=(int n) { pos += n; }
    void operator=(const Iterator2D& other) {
      mat = other.mat;
      pos = other.pos;
    }
    Iterator2D(const Iterator2D& other) : mat(other.mat), pos(other.pos) {}

   private:
    std::vector<std::vector<int>>& mat;
    int64_t pos = 0;
  };

 public:
  bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
    return std::binary_search(Iterator2D(matrix), Iterator2D(matrix).end(),
                              target);
  }
};
