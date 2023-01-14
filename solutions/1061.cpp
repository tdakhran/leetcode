#include <algorithm>
#include <array>
#include <queue>
#include <string>

class Solution {
 public:
  std::string smallestEquivalentString(std::string const &s1,
                                       std::string const &s2,
                                       std::string baseStr) {
    std::array<std::array<bool, 26>, 26> adj = {{{0}}};
    for (size_t i = 0; i < s1.size(); ++i) {
      size_t index1 = static_cast<size_t>(s1[i] - 'a');
      size_t index2 = static_cast<size_t>(s2[i] - 'a');
      adj[index1][index2] = adj[index2][index1] = true;
    }

    std::array<char, 128> match = {0};
    std::queue<size_t> q;

    for (auto letter : baseStr) {
      size_t letter_idx = static_cast<size_t>(letter - 'a');

      if (match[letter_idx]) continue;

      q.push(letter_idx);

      std::vector<size_t> group;

      while (not q.empty()) {
        auto idx = q.front();
        q.pop();

        group.push_back(idx);

        for (size_t i = 0; i < 26; ++i)
          if (adj[idx][i] and not match[i]) {
            q.push(i);
            match[i] = 1;
          }
      }

      auto min_idx = *std::min_element(begin(group), end(group));
      for (auto idx : group)
        match['a' + idx] = static_cast<char>('a' + min_idx);
    }

    for (auto &c : baseStr) c = match[static_cast<size_t>(c)];

    return baseStr;
  }
};
