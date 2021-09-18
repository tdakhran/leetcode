#include <string>
#include <vector>

class Solution {
 public:
  std::vector<std::string> addOperators(std::string num, int target) {
    std::vector<std::string> res;
    dfs(num, target, 0, 0, 0, "", res);
    return res;
  }

  void dfs(std::string& s, long target, size_t current_pos, long current_value,
           long pv, std::string current_result, std::vector<std::string>& res) {
    if (current_pos == s.size() && current_value == target) {
      res.push_back(current_result);
      return;
    }
    for (size_t pos = 1; pos <= s.size() - current_pos; pos++) {
      std::string tail = s.substr(current_pos, pos);
      if (pos > 1 && tail[0] == '0') {
        continue;
      }
      long n = stol(tail);
      if (current_pos == 0) {
        dfs(s, target, pos, n, n, tail, res);
        continue;
      }
      dfs(s, target, current_pos + pos, current_value + n, n,
          current_result + "+" + tail, res);
      dfs(s, target, current_pos + pos, current_value - n, -n,
          current_result + "-" + tail, res);
      dfs(s, target, current_pos + pos, current_value - pv + pv * n, pv * n,
          current_result + "*" + tail, res);
    }
  }
};
