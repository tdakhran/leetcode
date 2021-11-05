#include <list>

class FrontMiddleBackQueue {
  std::list<int> list_;
  std::list<int>::iterator middle_;

 public:
  FrontMiddleBackQueue() {}

  void pushFront(int val) {
    list_.push_front(val);
    if (list_.size() == 1) {
      middle_ = begin(list_);
    } else if (list_.size() & 1) {
      middle_ = prev(middle_);
    }
  }

  void pushMiddle(int val) {
    if (list_.empty()) {
      list_.push_front(val);
      middle_ = begin(list_);
    } else {
      list_.insert(middle_, val);
      if (list_.size() & 1) {
        middle_ = prev(middle_);
      }
    }
  }

  void pushBack(int val) {
    list_.push_back(val);
    if (list_.size() == 1) {
      middle_ = begin(list_);
    } else if ((list_.size() & 1) == 0) {
      middle_ = next(middle_);
    }
  }

  int popFront() {
    if (list_.size() == 0) {
      return -1;
    }

    auto result = list_.front();
    if (list_.size() > 1 and (list_.size() & 1)) {
      middle_ = next(middle_);
    }
    list_.pop_front();
    return result;
  }

  int popMiddle() {
    if (list_.size() == 0) {
      return -1;
    }

    int result = *middle_;
    if (list_.size() == 1) {
      list_.pop_front();
    } else if ((list_.size() & 1) == 0) {
      result = *prev(middle_);
      list_.erase(prev(middle_));
    } else {
      auto to_erase = middle_;
      middle_ = next(middle_);
      list_.erase(to_erase);
    }

    return result;
  }

  int popBack() {
    if (list_.size() == 0) {
      return -1;
    }
    auto result = list_.back();
    if (list_.size() > 1 and not(list_.size() & 1)) {
      middle_ = prev(middle_);
    }
    list_.pop_back();
    return result;
  }
};
