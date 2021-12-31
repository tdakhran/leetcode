#include <set>
#include <unordered_map>

class Leaderboard {
 private:
  std::unordered_map<int, int> player_scores;
  std::multiset<int> scores;

 public:
  Leaderboard() {}

  void addScore(int playerId, int score) {
    auto &prev_scores = player_scores[playerId];
    if (auto it = scores.find(prev_scores); it != end(scores)) {
      scores.erase(it);
    }
    prev_scores += score;
    scores.insert(prev_scores);
  }

  int top(int K) {
    int sum = 0;
    for (auto it = scores.crbegin(); K--; ++it) {
      sum += *it;
    }
    return sum;
  }

  void reset(int playerId) {
    auto &prev_scores = player_scores[playerId];
    scores.erase(scores.find(prev_scores));
    prev_scores = 0;
    scores.insert(0);
  }
};
