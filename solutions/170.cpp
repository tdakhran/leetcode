#include <unordered_map>

class TwoSum {
  std::unordered_map<int64_t, size_t> counts;

 public:
  void add(int number) { ++counts[number]; }

  bool find(int value) {
    for (auto [number, count] : counts) {
      int64_t another = value - number;
      if ((another == number and count > 1) or
          (another != number and counts.count(another))) {
        return true;
      }
    }
    return false;
  }
};
