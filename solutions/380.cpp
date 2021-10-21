#include <unordered_map>
#include <vector>

class RandomizedSet {
  std::unordered_map<int, size_t> hash;
  std::vector<int> storage;

 public:
  RandomizedSet() {}

  bool insert(int val) {
    auto it = hash.find(val);
    if (it == end(hash)) {
      hash.emplace_hint(it, val, storage.size());
      storage.push_back(val);
      return true;
    }
    return false;
  }

  bool remove(int val) {
    if (auto it = hash.find(val); it != end(hash)) {
      hash[storage.back()] = it->second;
      storage[it->second] = storage.back();
      storage.pop_back();
      hash.erase(it);
      return true;
    }
    return false;
  }

  int getRandom() {
    return storage[static_cast<size_t>(rand()) % storage.size()];
  }
};
