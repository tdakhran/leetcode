#include <algorithm>
#include <unordered_map>
#include <vector>

class FenwickTree {
 private:
  std::vector<int> data;

  int getParent(int i) const { return i - (i & (-i)); }
  int getNext(int i) const { return i + (i & (-i)); }

 public:
  FenwickTree(size_t n) : data(n + 1) {}

  int getSum(int i) const {
    int sum = 0;
    ++i;
    while (i > 0) {
      sum += data[static_cast<size_t>(i)];
      i = getParent(i);
    }
    return sum;
  }

  void update(int i, int v) {
    ++i;
    while (static_cast<size_t>(i) < data.size()) {
      data[static_cast<size_t>(i)] += v;
      i = getNext(i);
    }
  }
};

class Solution {
 public:
  int reversePairs(std::vector<int>& nums) {
    auto su_nums = nums;
    sort(begin(su_nums), end(su_nums));
    su_nums.erase(std::unique(su_nums.begin(), su_nums.end()), end(su_nums));

    std::unordered_map<int, int> num2pos;
    for (size_t pos = 0; pos < su_nums.size(); ++pos) {
      num2pos[su_nums[pos]] = static_cast<int>(su_nums.size() - pos);
    }

    FenwickTree ft(su_nums.size() + 1);

    int result = 0;
    for (auto n : nums) {
      if (auto ub = std::upper_bound(begin(su_nums), end(su_nums), 2ll * n);
          ub != end(su_nums)) {
        result += ft.getSum(num2pos[*ub]);
      }
      ft.update(num2pos[n], 1);
    }

    return result;
  }
};
