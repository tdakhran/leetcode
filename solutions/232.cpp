#include <stack>

class MyQueue {
  std::stack<int> stack, buffer;

  void normalize() {
    if (stack.empty()) {
      while (not buffer.empty()) {
        stack.push(buffer.top());
        buffer.pop();
      }
    }
  }

 public:
  MyQueue() {}

  void push(int x) { buffer.push(x); }

  int pop() {
    normalize();
    auto result = stack.top();
    stack.pop();
    return result;
  }

  int peek() {
    normalize();
    return stack.top();
  }

  bool empty() {
    normalize();
    return stack.empty();
  }
};
