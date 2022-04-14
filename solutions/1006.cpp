#include <functional>
#include <numeric>
#include <vector>

class Solution {
 public:
  int clumsy(int n) {
    std::vector<int> st(1, n--);
    std::array<std::function<int(int, int)>, 4> ops{
        {std::multiplies<int>(), std::divides<int>(), std::plus<int>(),
         std::minus<int>()}};

    for (size_t op = 0; n; op = (op + 1) % 4, --n) {
      if (op == 3) {
        st.push_back(0);
      }
      st.back() = ops[op](st.back(), n);
    }
    return std::accumulate(begin(st), end(st), 0);
  }
};
