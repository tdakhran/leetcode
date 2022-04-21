#include <vector>

class MyHashSet {
  using Bucket = std::vector<int>;
  static inline constexpr size_t n = 1024;
  std::vector<Bucket> buckets{n};

  constexpr size_t hash(int key) { return static_cast<size_t>(key) % n; }

  Bucket &bucket(int key) { return buckets[hash(key)]; }

 public:
  MyHashSet() {}

  void add(int key) {
    if (not contains(key)) {
      bucket(key).push_back(key);
    }
  }

  void remove(int key) {
    auto &b = bucket(key);
    for (auto &val : b) {
      if (val == key) {
        std::swap(val, b.back());
        b.pop_back();
        return;
      }
    }
  }

  bool contains(int key) {
    const auto &b = bucket(key);
    for (auto val : b) {
      if (val == key) {
        return true;
      }
    }
    return false;
  }
};
