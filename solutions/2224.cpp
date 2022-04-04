#include <array>
#include <string>

class Solution {
 public:
  int convertTime(std::string current, std::string correct) {
    auto to_minutes = [](const std::string &s) {
      auto to_digit = [](char a, char b) { return a * 10 + b - 11 * '0'; };
      auto hours = to_digit(s[0], s[1]);
      auto minutes = to_digit(s[3], s[4]);
      return hours * 60 + minutes;
    };
    auto current_m = to_minutes(current);
    auto correct_m = to_minutes(correct);
    auto delta = correct_m - current_m;

    std::array<int, 4> moves{{60, 15, 5, 1}};
    int count = 0;
    for (auto m : moves) {
      count += delta / m;
      delta %= m;
    }

    return count;
  }
};
