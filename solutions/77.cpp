#include <functional>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> combine(int n, size_t k) {
    std::vector<std::vector<int>> result;
    std::vector<int> current;

    std::function<void()> generate = [&generate, &result, &current, n, k]() {
      if (current.size() == k) {
        result.push_back(current);
        return;
      }
      for (int num = current.empty() ? 1 : current.back() + 1; num <= n;
           ++num) {
        current.push_back(num);
        generate();
        current.pop_back();
      }
    };

    generate();

    return result;
  }
};
