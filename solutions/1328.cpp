#include <string>

class Solution {
 public:
  std::string breakPalindrome(std::string palindrome) {
    if (palindrome.size() == 1) {
      return "";
    }
    for (size_t pos = 0; pos < palindrome.size() / 2; ++pos) {
      auto &c = palindrome[pos];
      if (c != 'a') {
        c = 'a';
        return palindrome;
      }
    }
    palindrome.back() = 'b';
    return palindrome;
  }
};
