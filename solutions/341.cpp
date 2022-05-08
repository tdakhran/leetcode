#include <stack>
#include <vector>

class NestedIterator {
  std::stack<NestedInteger> stack_;

 public:
  NestedIterator(std::vector<NestedInteger> &nestedList) {
    for (auto it = nestedList.rbegin(); it != nestedList.rend(); ++it) {
      stack_.push(*it);
    }
  }

  int next() {
    auto nested_integer = stack_.top();
    stack_.pop();
    return nested_integer.getInteger();
  }

  bool hasNext() {
    if (stack_.empty()) {
      return false;
    }

    if (stack_.top().isInteger()) {
      return true;
    }

    auto nested_integer = stack_.top();
    stack_.pop();

    auto &nested_list = nested_integer.getList();
    for (auto it = nested_list.rbegin(); it != nested_list.rend(); ++it) {
      stack_.push(*it);
    }
    return hasNext();
  }
};
