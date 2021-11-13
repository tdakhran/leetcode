#include <stack>
#include <vector>

class Solution {
 public:
  std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
    std::vector<int> result(temperatures.size());
    std::stack<std::pair<size_t, int>> st;

    for (size_t pos = 0; pos < temperatures.size(); ++pos) {
      auto temp = temperatures[pos];
      while (not st.empty() and st.top().second < temp) {
        result[st.top().first] = static_cast<int>(pos - st.top().first);
        st.pop();
      }
      st.push({pos, temp});
    }
    return result;
  }
};
