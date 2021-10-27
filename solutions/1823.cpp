class Solution {
  struct Node {
    explicit Node(int val_in, Node *next_in = nullptr)
        : next(next_in), val(val_in) {}
    Node *next;
    int val;
  };

 public:
  int findTheWinner(int n, int k) {
    auto head = new Node(1);
    auto tail = head;

    for (int i = 2; i <= n; ++i) {
      tail = tail->next = new Node(i);
    }
    tail->next = head;
    while (head != head->next) {
      for (int i = 0; i + 1 < k; ++i) {
        head = head->next;
      }
      head->val = head->next->val;
      auto to_delete = head->next;
      head->next = to_delete->next;
      delete to_delete;
    }
    return head->val;
  }
};
