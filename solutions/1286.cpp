#include <cassert>
#include <stack>
#include <string>

class CombinationIterator {
  std::string chars;
  size_t length;

  std::string cur;
  std::stack<size_t> poses;

 public:
  CombinationIterator(std::string characters, int combinationLength)
      : chars(characters), length(static_cast<size_t>(combinationLength)) {
    for (size_t pos = 0; pos < chars.size() and poses.size() < length; ++pos) {
      cur.push_back(chars[pos]);
      poses.push(pos);
    }
  }

  std::string next() {
    auto result = cur;
    while (not poses.empty() and poses.top() + 1 == chars.size()) {
      cur.pop_back();
      poses.pop();
    }
    while (not poses.empty()) {
      auto start = poses.top() + 1;
      poses.pop();
      cur.pop_back();

      for (size_t pos = start; pos < chars.size() and poses.size() < length;
           ++pos) {
        cur.push_back(chars[pos]);
        poses.push(pos);
      }
      if (cur.size() == length) {
        return result;
      }
    }
    return result;
  }

  bool hasNext() { return cur.size() == length; }
};
