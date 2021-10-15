#include <array>

class MyHashMap {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpadded"
  struct Bucket {
    std::array<Bucket *, 2> ch{nullptr};
    int value = -1;
  };
#pragma clang diagnostic pop

  Bucket root;

 public:
  /** Initialize your data structure here. */
  MyHashMap() {}

  /** value will always be non-negative. */
  void put(int key, int value) {
    auto it = &root;
    while (key) {
      unsigned bit = (key & 1);
      key >>= 1;
      if (not it->ch[bit]) {
        it->ch[bit] = new Bucket();
      }
      it = it->ch[bit];
    }
    it->value = value;
  }

  /** Returns the value to which the specified key is mapped, or -1 if this map
   * contains no mapping for the key */
  int get(int key) {
    auto it = &root;
    while (key) {
      unsigned bit = (key & 1);
      key >>= 1;
      if (not it->ch[bit]) {
        return -1;
      }
      it = it->ch[bit];
    }
    return it->value;
  }

  /** Removes the mapping of the specified value key if this map contains a
   * mapping for the key */
  void remove(int key) { put(key, -1); }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
