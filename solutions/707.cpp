class MyLinkedList {
  struct Node {
    explicit Node(int val_in, Node *next_in = nullptr)
        : val(val_in), next(next_in) {}
    int val{0};
    Node *next{nullptr};
  };

  Node *head_{nullptr};
  size_t size{0};

 public:
  MyLinkedList() {}

  int get(int index) {
    if (index >= size) {
      return -1;
    }
    auto it = head_;
    while (index--) {
      it = it->next;
    }
    return it->val;
  }

  void addAtHead(int val) {
    ++size;
    head_ = new Node(val, head_);
  }

  void addAtTail(int val) {
    if (!head_) {
      return addAtHead(val);
    }
    auto it = head_;
    while (it->next) {
      it = it->next;
    }
    it->next = new Node(val);
    ++size;
  }

  void addAtIndex(int index, int val) {
    if (index == 0) {
      return addAtHead(val);
    } else if (index == size) {
      return addAtTail(val);
    } else if (index < size) {
      ++size;
      auto it = head_;
      while (--index) {
        it = it->next;
      }
      it->next = new Node(val, it->next);
    }
  }

  void deleteAtIndex(int index) {
    if (index >= size) {
      return;
    }
    --size;

    if (index == 0) {
      head_ = head_->next;
      return;
    }
    auto it = head_;
    while (--index) {
      it = it->next;
    }
    it->next = it->next->next;
  }
};
