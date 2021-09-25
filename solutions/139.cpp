#include <array>
#include <vector>

class Solution {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpadded"
  struct TrieNode {
    std::array<TrieNode *, 26> ch{nullptr};
    bool word = false;
  };
#pragma clang diagnostic pop

 public:
  bool wordBreak(std::string s, std::vector<std::string> &wordDict) {
    TrieNode dict;
    // fill trie dictionary
    for (const auto &word : wordDict) {
      auto it = &dict;
      for (auto c : word) {
        auto &ch = it->ch[static_cast<size_t>(c - 'a')];
        if (!ch) {
          ch = new TrieNode();
        }
        it = ch;
      }
      it->word = true;
    }

    std::vector<bool> reachable(s.size() + 1);
    reachable[0] = true;

    for (size_t start_pos = 0; start_pos < s.size(); ++start_pos) {
      if (not reachable[start_pos]) {
        continue;
      }
      auto dict_it = &dict;
      for (size_t pos = start_pos; pos < s.size(); ++pos) {
        dict_it = dict_it->ch[static_cast<size_t>(s[pos] - 'a')];
        if (!dict_it) {
          break;
        }
        if (dict_it->word) {
          reachable[pos + 1] = true;
        }
      }
    }
    return reachable.back();
  }
};
