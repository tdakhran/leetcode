#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

class Solution {
 public:
  int ladderLength(std::string beginWord, std::string endWord,
                   std::vector<std::string>& wordList) {
    std::unordered_set<std::string_view> words(begin(wordList), end(wordList));
    std::unordered_set<std::string_view> visited;
    std::queue<std::string_view> q;
    q.push(beginWord);

    for (int steps = 1; not q.empty(); ++steps) {
      auto qsize = q.size();
      while (qsize--) {
        std::string word(q.front());
        q.pop();

        if (word == endWord) {
          return steps;
        }

        for (auto& c : word) {
          for (char cand = 'a'; cand <= 'z'; ++cand) {
            std::swap(c, cand);
            if (auto it = words.find(word);
                it != end(words) and visited.insert(*it).second) {
              q.push(*it);
            }
            std::swap(c, cand);
          }
        }
      }
    }
    return 0;
  }
};
