class Solution {
 public:
  PolyNode* addPoly(PolyNode* poly1, PolyNode* poly2) {
    PolyNode preHead;
    auto tail = &preHead;
    PolyNode* it[2] = {poly1, poly2};

    while (it[0] and it[1]) {
      if (it[0]->power == it[1]->power) {
        auto coeff = it[0]->coefficient + it[1]->coefficient;

        if (coeff) {
          tail = tail->next = it[0];
          it[0]->coefficient = coeff;
        }
        it[0] = it[0]->next;
        it[1] = it[1]->next;
      } else {
        auto idx = it[0]->power < it[1]->power;
        tail = tail->next = it[idx];
        it[idx] = it[idx]->next;
      }
    }

    for (auto& i : it) {
      while (i) {
        tail = tail->next = i;
        i = i->next;
      }
    }
    tail->next = nullptr;
    return preHead.next;
  }
};
