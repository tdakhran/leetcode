#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
  struct RollingHash {
    explicit RollingHash(std::string_view sv) {
      for (auto c : sv) {
        hash_ = (hash_ * x + c) % modulo;
        coeff_ = (coeff_ * x) % modulo;
        queue_.push(c);
      }
    }
    void update(char c) {
      hash_ = (hash_ * x + c) % modulo;
      hash_ = (hash_ - queue_.front() * coeff_) % modulo;
      hash_ = hash_ < 0 ? hash_ + modulo : hash_;
      queue_.pop();
      queue_.push(c);
    }
    operator int64_t() const { return hash_; }

   private:
    static inline constexpr int64_t x = 257;
    static inline constexpr int64_t modulo = 10000000019;
    int64_t hash_{0};
    int64_t coeff_{1};
    std::queue<char> queue_;
  };

 public:
  std::string longestDupSubstring(std::string s) {
    auto longest_dup_substr = [](std::string_view sv,
                                 size_t length) -> std::string_view {
      std::unordered_map<int64_t, std::vector<size_t>> seen;
      auto hash = RollingHash(sv.substr(0, length));
      seen[hash].push_back(0);
      for (size_t pos = length; pos < sv.size(); ++pos) {
        hash.update(sv[pos]);
        auto &hashes = seen[hash];
        for (auto start : hashes) {
          if (sv.substr(start, length) == sv.substr(pos - length + 1, length)) {
            return sv.substr(start, length);
          }
        }
        hashes.push_back(pos - length + 1);
      }
      return std::string_view();
    };

    size_t lo = 1;
    size_t hi = s.size();
    std::string_view result;
    while (lo < hi) {
      size_t mi = lo + (hi - lo) / 2;
      if (auto cand = longest_dup_substr(s, mi); not cand.empty()) {
        result = cand;
        lo = mi + 1;
      } else {
        hi = mi;
      }
    }

    return std::string(result);
  }
};
