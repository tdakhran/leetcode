#include <vector>

class Solution {
 public:
  int maxSumAfterOperation(std::vector<int>& nums) {
    struct State {
      int sum{0};
      int sum_with_squared{0};

      int max() const { return std::max(sum, sum_with_squared); }
    };
    State state;
    int result = 0;
    for (auto num : nums) {
      state = {std::max(num, state.sum + num),
               std::max(state.sum_with_squared + num,
                        std::max(state.sum + num * num, num * num))};
      result = std::max(result, state.max());
    }

    return result;
  }
};
