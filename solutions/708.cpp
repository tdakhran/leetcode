class Solution {
 public:
  Node* insert(Node* head, int insertVal) {
    auto node = new Node(insertVal);
    if (!head) {
      node->next = node;
      return node;
    }
    auto target = head;
    for (auto it = head;; it = it->next) {
      if (it->val <= insertVal and insertVal <= it->next->val) {
        target = it;
        break;
      }
      if (target->val <= it->val) {
        target = it;
      }
      if (it->next == head) {
        break;
      }
    }
    node->next = target->next;
    target->next = node;
    return head;
  }
};
