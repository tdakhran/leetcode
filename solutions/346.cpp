#include <queue>

class MovingAverage {
  std::queue<int> q;
  size_t max_size{0};
  int sum{0};

 public:
  MovingAverage(int size) : max_size(static_cast<size_t>(size)) {}

  double next(int val) {
    q.push(val);
    sum += val;

    if (q.size() > max_size) {
      sum -= q.front();
      q.pop();
    }

    return sum / static_cast<double>(q.size());
  }
};
