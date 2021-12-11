class Solution {
 public:
  ListNode* sortList(ListNode* head) {
    if (not head) {
      return nullptr;
    }
    bool sorted = true;
    auto it = head;
    while (it->next) {
      if (it->val > it->next->val) {
        sorted = false;
        break;
      }
      it = it->next;
    }
    if (sorted) {
      return head;
    }

    auto p = head;
    it = head->next;
    p->next = nullptr;

    ListNode le(0), gt(0);
    auto tail_le = &le;
    auto tail_gt = &gt;

    while (it) {
      auto next = it->next;
      it->next = nullptr;
      if (it->val <= p->val) {
        tail_le->next = it;
        tail_le = it;
      } else {
        tail_gt->next = it;
        tail_gt = it;
      }
      it = next;
    }

    auto sle = sortList(le.next);
    p->next = sortList(gt.next);

    if (not sle) {
      return p;
    }
    it = sle;
    while (it->next) {
      it = it->next;
    }
    it->next = p;
    return sle;
  }
};
