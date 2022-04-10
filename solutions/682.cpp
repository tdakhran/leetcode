#include <numeric>
#include <string>
#include <vector>

class Solution {
 public:
  int calPoints(std::vector<std::string>& ops) {
    std::vector<int> scores;

    for (const auto& op : ops) {
      if (op == "+") {
        scores.push_back(scores.back() + *next(scores.rbegin()));
      } else if (op == "D") {
        scores.push_back(2 * scores.back());
      } else if (op == "C") {
        scores.pop_back();
      } else {
        scores.push_back(stoi(op));
      }
    }
    return std::accumulate(begin(scores), end(scores), 0);
  }
};
