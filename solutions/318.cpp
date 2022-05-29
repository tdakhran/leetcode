#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
  static size_t calc_hash(const std::string &str) {
    return std::accumulate(begin(str), end(str), 0ull, [](size_t acc, char c) {
      return acc | (1 << (c - 'a'));
    });
  }

 public:
  size_t maxProduct(std::vector<std::string> &words) {
    std::unordered_map<size_t, size_t> lengths;
    size_t result = 0;

    for (const auto &word : words) {
      auto hash = calc_hash(word);
      auto length = word.size();

      if (lengths[hash] >= length) {
        continue;
      }

      lengths[hash] = length;
      for (const auto &[other_hash, other_length] : lengths) {
        if (!(hash & other_hash)) {
          result = std::max(result, other_length * length);
        }
      }
    }
    return result;
  }
};
