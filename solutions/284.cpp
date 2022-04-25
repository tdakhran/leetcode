#include <optional>
#include <vector>

class PeekingIterator : public Iterator {
 public:
  PeekingIterator(const std::vector<int>& nums) : Iterator(nums) {
    if (Iterator::hasNext()) {
      cached_ = Iterator::next();
    }
  }

  int peek() { return cached_.value(); }

  int next() {
    int result = cached_.value();
    cached_ = Iterator::hasNext() ? decltype(cached_)(Iterator::next())
                                  : std::nullopt;
    return result;
  }

  bool hasNext() const { return cached_.has_value(); }

 private:
  std::optional<int> cached_;
};
