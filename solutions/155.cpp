#include <stack>

class MinStack {
  std::stack<std::pair<int, int>> st;

 public:
  void push(int v) { st.push({v, st.empty() ? v : std::min(v, getMin())}); }
  void pop() { st.pop(); }
  int top() { return st.top().first; }
  int getMin() { return st.top().second; }
};
