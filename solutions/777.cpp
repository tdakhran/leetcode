#include <string>
#include <vector>

class Solution {
 public:
  bool canTransform(std::string source, std::string target) {
    std::vector<std::pair<char, size_t>> s_pos;
    std::vector<std::pair<char, size_t>> t_pos;

    for (size_t p = 0; p < source.size(); ++p) {
      if (source[p] != 'X') {
        s_pos.emplace_back(source[p], p);
      }
      if (target[p] != 'X') {
        t_pos.emplace_back(target[p], p);
      }
    }

    if (s_pos.size() != t_pos.size()) {
      return false;
    }

    for (auto is = begin(s_pos), it = begin(t_pos); is != end(s_pos);
         ++is, ++it) {
      if (is->first != it->first) {
        return false;
      }

      if (is->first == 'L' and is->second < it->second) {
        return false;
      }
      if (is->first == 'R' and is->second > it->second) {
        return false;
      }
    }

    return true;
  }
};
