#include <iterator>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
  template <typename T, typename U>
  bool match(T from, T to, U other) {
    std::unordered_map<typename T::value_type, typename U::value_type> m;
    for (auto bb = from; bb != to; ++bb, ++other) {
      if (auto it = m.find(*bb); it == end(m))
        m[*bb] = *other;
      else if (it->second != *other)
        return false;
    }
    return true;
  }

 public:
  bool wordPattern(std::string pattern, std::string s) {
    std::istringstream iss(s);
    std::vector<std::string> words{std::istream_iterator<std::string>{iss},
                                   std::istream_iterator<std::string>{}};

    return words.size() == pattern.size() &&
           match(begin(words), end(words), begin(pattern)) and
           match(begin(pattern), end(pattern), begin(words));
  }
};
