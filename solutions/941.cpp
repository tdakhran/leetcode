#include <vector>

class Solution {
 public:
  bool validMountainArray(std::vector<int>& arr) {
    size_t pos = 0;
    while (pos + 1 < arr.size() and arr[pos] < arr[pos + 1]) {
      ++pos;
    }
    if (pos == 0 or pos + 1 == arr.size()) {
      return false;
    }
    while (pos + 1 < arr.size() and arr[pos] > arr[pos + 1]) {
      ++pos;
    }
    return pos + 1 == arr.size();
  }
};
