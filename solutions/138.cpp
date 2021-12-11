#include <unordered_map>

class Solution {
  std::unordered_map<Node*, Node*> match;

 public:
  Node* copyRandomList(Node* head) {
    if (not head) {
      return nullptr;
    }
    if (match.count(head)) {
      return match[head];
    }
    auto node = new Node(head->val);
    match[head] = node;
    node->next = copyRandomList(head->next);
    node->random = copyRandomList(head->random);
    return node;
  }
};
