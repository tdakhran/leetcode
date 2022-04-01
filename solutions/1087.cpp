#include <algorithm>
#include <string>
#include <vector>

class Solution {
 public:
  std::vector<std::string> expand(std::string s) {
    auto tokens = [](const std::string &str) {
      std::vector<std::string> result;
      std::string cur;
      bool brackets_mode = false;

      for (auto c : str) {
        if (c == '{') {
          brackets_mode = true;
        } else if (c == '}') {
          brackets_mode = false;
          std::sort(begin(cur), end(cur));
          result.push_back(cur);
          cur.clear();
        } else if (c == ',') {
          continue;
        } else if (brackets_mode) {
          cur.push_back(c);
        } else {
          result.push_back(std::string(1, c));
        }
      }
      return result;
    }(s);

    std::vector<std::string> result;
    std::string current;

    std::function<void(size_t)> gen = [&](size_t index) {
      if (index == tokens.size()) {
        result.push_back(current);
        return;
      }

      for (auto c : tokens[index]) {
        current.push_back(c);
        gen(index + 1);
        current.pop_back();
      }
    };
    gen(0);

    return result;
  }
};
