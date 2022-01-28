#include <array>
#include <queue>

class WordDictionary {
  struct TrieNode {
    bool word = false;
    std::array<TrieNode *, 26> ch{nullptr};
  };
  TrieNode root;

 public:
  /** Initialize your data structure here. */
  WordDictionary() {}

  /** Adds a word into the data structure. */
  void addWord(std::string word) {
    auto it = &root;
    for (auto c : word) {
      auto &ch = it->ch[static_cast<size_t>(c - 'a')];
      if (not ch) {
        ch = new TrieNode();
      }
      it = ch;
    }
    it->word = true;
  }

  /** Returns if the word is in the data structure. A word could contain the dot
   * character '.' to represent any one letter. */
  bool search(std::string word) {
    std::queue<std::pair<TrieNode *, size_t>> q;
    q.push({&root, 0});
    while (not q.empty()) {
      auto [r, pos] = q.front();
      q.pop();
      while (r and pos < word.size() and isalpha(word[pos])) {
        r = r->ch[static_cast<size_t>(word[pos] - 'a')];
        ++pos;
      }
      if (not r) {
        continue;
      }
      if (pos == word.size()) {
        if (r->word) {
          return true;
        }
        continue;
      }
      for (auto ch : r->ch) {
        if (ch) {
          q.push({ch, pos + 1});
        }
      }
    }
    return false;
  }
};
