#include <array>

class Trie {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpadded"
  struct TrieNode {
    std::array<TrieNode *, 26> ch{nullptr};
    bool word = false;
  };
  TrieNode root;
#pragma clang diagnostic pop

  TrieNode *traverse(TrieNode *it, const std::string &word, bool create) {
    for (size_t pos = 0; pos < word.size() and it; ++pos) {
      auto &ch = it->ch[static_cast<size_t>(word[pos] - 'a')];
      if (!ch and create) {
        ch = new TrieNode();
      }
      it = ch;
    }
    return it;
  }

 public:
  Trie() {}

  void insert(std::string word) { traverse(&root, word, true)->word = true; }

  bool search(std::string word) {
    auto it = traverse(&root, word, false);
    return it and it->word;
  }

  bool startsWith(std::string prefix) { return traverse(&root, prefix, false); }
};
