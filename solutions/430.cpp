#include <stack>

class Solution {
 public:
  Node* flatten(Node* head) {
    std::stack<Node*> st;

    for (auto it = head; it; it = it->next) {
      if (it->child) {
        if (it->next) {
          st.push(it->next);
        }
        it->next = it->child;
        it->child = nullptr;
        it->next->prev = it;
      } else if (not it->next and not st.empty()) {
        auto next = st.top();
        st.pop();
        it->next = next;
        it->next->prev = it;
      }
    }

    return head;
  }
};
