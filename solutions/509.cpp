#include <queue>

class Solution {
 public:
  int fib(int n) {
    if (n == 0) {
      return n;
    }

    std::queue<int> q;
    q.push(0);
    q.push(1);
    while (--n > 0) {
      auto f_n_2 = q.front();
      q.pop();
      q.push(q.front() + f_n_2);
    }
    q.pop();
    return q.front();
  }
};
