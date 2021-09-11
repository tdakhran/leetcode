#include <stack>
#include <string>
#include <variant>
#include <vector>

class Solution {
  struct OpeningBracket {};
  struct ClosingBracket {};
  struct Sign {
    int value;
  };
  struct MinusSign {};

  using Token = std::variant<OpeningBracket, ClosingBracket, Sign, int>;

  auto tokenize(const std::string &s) {
    std::vector<Token> tokens;
    for (auto c : s) {
      if (isdigit(c)) {
        if (not tokens.empty() and std::holds_alternative<int>(tokens.back())) {
          tokens.back() = std::get<int>(tokens.back()) * 10 + (c - '0');
        } else {
          tokens.push_back(c - '0');
        }
        continue;
      }
      switch (c) {
        case '(':
          tokens.push_back(OpeningBracket{});
          break;
        case ')':
          tokens.push_back(ClosingBracket{});
          break;
        case '+':
          tokens.push_back(Sign{1});
          break;
        case '-':
          tokens.push_back(Sign{-1});
          break;
        default:
          break;
      }
    }
    return tokens;
  }

  void handle(int arg) { result += last_seen_sign * signs.top() * arg; }

  void handle(OpeningBracket) {
    signs.push(last_seen_sign * signs.top());
    last_seen_sign = 1;
  }

  void handle(ClosingBracket) { signs.pop(); }
  void handle(Sign arg) { last_seen_sign = arg.value; }

 private:
  int result = 0;
  int last_seen_sign = 1;
  std::stack<int> signs;

 public:
  int calculate(std::string s) {
    signs.push(1);
    for (const auto &token : tokenize(s)) {
      std::visit([this](const auto &arg) { handle(arg); }, token);
    }
    return result;
  }
};
