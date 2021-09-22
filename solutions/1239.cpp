#include <optional>
#include <vector>

class Solution {
  struct Chunk {
    explicit Chunk(unsigned mask_in, unsigned size_in)
        : mask(mask_in), size(size_in) {}

    bool appendable(const Chunk &o) const { return (mask & o.mask) == 0; }
    void append(const Chunk &o) {
      mask |= o.mask;
      size += o.size;
    }

    Chunk() = default;

   public:
    unsigned mask{0};
    unsigned size{0};
  };

  std::optional<uint32_t> get_mask(const std::string &s) {
    uint32_t mask = 0;
    for (auto c : s) {
      unsigned bit = 1 << (c - 'a');
      if (mask & bit) {
        return std::nullopt;
      }
      mask |= bit;
    }
    return mask;
  }

 public:
  int maxLength(std::vector<std::string> &arr) {
    std::vector<Chunk> chunks;
    for (const auto &s : arr) {
      if (auto mask = get_mask(s); mask) {
        chunks.emplace_back(*mask, s.size());
      }
    }

    size_t N = chunks.size();
    unsigned result = 0;
    for (size_t mask = 0; mask < (1 << N); ++mask) {
      Chunk chunk;
      for (size_t pos = 0; pos < N; ++pos) {
        if (((1 << pos) & mask) and chunk.appendable(chunks[pos])) {
          chunk.append(chunks[pos]);
        }
      }
      result = std::max(result, chunk.size);
    }
    return static_cast<int>(result);
  }
};
