#include <array>
#include <queue>
#include <string>
#include <vector>

class StreamChecker {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpadded"
  struct TrieNode {
    std::array<TrieNode *, 26> ch{nullptr};
    bool word = false;
  };
#pragma clang diagnostic pop
  TrieNode root;
  std::queue<TrieNode *> ptrs;

 public:
  StreamChecker(std::vector<std::string> &words) {
    for (const auto &word : words) {
      auto it = &root;
      for (auto c : word) {
        auto index = static_cast<size_t>(c - 'a');
        auto &ch = it->ch[index];
        if (!ch) {
          ch = new TrieNode();
        }
        it = ch;
      }
      it->word = true;
    }
  }

  bool query(char letter) {
    bool found = false;
    auto index = static_cast<size_t>(letter - 'a');
    ptrs.push(&root);

    auto size = ptrs.size();
    while (size--) {
      auto it = ptrs.front();
      ptrs.pop();

      if (auto ch = it->ch[index]; ch) {
        ptrs.push(ch);
        found |= ch->word;
      }
    }

    return found;
  }
};
