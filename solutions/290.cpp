#include <string>
#include <unordered_map>

class Solution {
 public:
  bool wordPattern(std::string pattern, std::string str) {
    std::string_view str_sv(str);
    auto pattern_it = begin(pattern);

    std::unordered_map<char, std::string_view> c2s;
    std::unordered_map<std::string_view, char> s2c;
    for (size_t start_pos = 0; start_pos < str_sv.size(); ++pattern_it) {
      auto next_space_pos =
          std::min(str_sv.find(' ', start_pos), str_sv.size());

      if (pattern_it == end(pattern)) {
        return false;
      }
      auto word = str_sv.substr(start_pos, next_space_pos - start_pos);
      auto str_it = s2c.find(word);
      auto pat_it = c2s.find(*pattern_it);

      if (str_it != end(s2c)) {
        if (str_it->second != *pattern_it) {
          return false;
        }
        if (pat_it == end(c2s) or pat_it->second != word) {
          return false;
        }
      } else if (pat_it != end(c2s)) {
        return false;
      } else {
        c2s.emplace_hint(pat_it, *pattern_it, word);
        s2c.emplace_hint(str_it, word, *pattern_it);
      }

      start_pos = next_space_pos + 1;
    }

    return pattern_it == end(pattern);
  }
};
