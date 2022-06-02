#include <functional>
#include <string>

class Solution {
 public:
  long long smallestNumber(long long num) {
    auto str = std::to_string(std::abs(num));

    sort(begin(str), end(str),
         num > 0 ? std::function(std::less<char>())
                 : std::function(std::greater<char>()));

    if (num > 0) {
      std::swap(str[0], str[str.find_first_not_of('0')]);
    }

    return (num < 0 ? -1 : 1) * stoll(str);
  }
};
