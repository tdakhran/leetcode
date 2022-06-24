#include <string>
#include <unordered_map>

class Solution {
  static bool injection(const std::string &from, const std::string &to) {
    std::unordered_map<char, char> m;
    for (size_t pos = 0; pos < from.size(); ++pos) {
      auto from_char = from[pos];
      auto to_char = to[pos];

      if (auto it = m.find(from_char); it != end(m) and it->second != to_char) {
        return false;
      }

      m[from_char] = to_char;
    }
    return true;
  }

 public:
  static bool isIsomorphic(const std::string &s, const std::string &t) {
    return injection(s, t) and injection(t, s);
  }
};
