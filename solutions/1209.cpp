#include <stack>
#include <string>
#include <utility>

class Solution {
 public:
  std::string removeDuplicates(std::string s, size_t k) {
    std::stack<size_t> count;
    std::string result;

    for (auto c : s) {
      if (count.empty() or result.back() != c) {
        count.push(0);
      }
      result.push_back(c);

      if (++count.top() == k) {
        result.erase(result.size() - k);
        count.pop();
      }
    }
    return result;
  }
};
