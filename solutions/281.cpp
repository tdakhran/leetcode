#include <array>
#include <vector>

class ZigzagIterator {
  std::array<std::vector<int>::iterator, 2> it;
  std::array<std::vector<int>::iterator, 2> ends;
  size_t last{0};

 public:
  ZigzagIterator(std::vector<int>& v1, std::vector<int>& v2)
      : it{begin(v1), begin(v2)}, ends{end(v1), end(v2)} {}

  int next() {
    if (it[last] != ends[last]) {
      last = 1 - last;
      return *it[1 - last]++;
    }
    return *it[1 - last]++;
  }

  bool hasNext() { return it[0] != ends[0] or it[1] != ends[1]; }
};
