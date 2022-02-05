#include <array>
#include <functional>
#include <queue>
#include <vector>

class Solution {
 public:
  int minimumOperations(std::vector<int>& nums, size_t start, int goal) {
    constexpr size_t MAX_VALUE = 1000;
    std::array<int, MAX_VALUE + 1> steps{0};
    std::queue<size_t> q;

    const std::array<std::function<int(int, int)>, 3> operations{
        std::plus<int>(), std::minus<int>(), std::bit_xor<int>()};

    steps[start] = 1;
    q.push(start);

    while (not q.empty()) {
      auto x = q.front();
      q.pop();

      for (auto n : nums) {
        for (const auto& operation : operations) {
          auto next = operation(static_cast<int>(x), n);
          if (next == goal) {
            return steps[x];
          }

          if (size_t idx = static_cast<size_t>(next);
              idx <= MAX_VALUE and steps[idx] == 0) {
            steps[idx] = steps[x] + 1;
            q.push(idx);
          }
        }
      }
    }
    return -1;
  }
};
