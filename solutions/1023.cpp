#include <algorithm>
#include <string>
#include <vector>

class Solution {
 public:
  std::vector<bool> camelMatch(std::vector<std::string>& queries,
                               std::string pattern) {
    std::vector<bool> result;
    result.reserve(queries.size());
    std::transform(begin(queries), end(queries), std::back_inserter(result),
                   [&pattern](const auto& s) {
                     auto ip = begin(pattern);
                     auto is = begin(s);

                     while (is != end(s)) {
                       if (ip != end(pattern) && *is == *ip) {
                         ++is;
                         ++ip;
                       } else if (std::islower(*is)) {
                         ++is;
                       } else {
                         return false;
                       }
                     }
                     return ip == end(pattern);
                   });
    return result;
  }
};
