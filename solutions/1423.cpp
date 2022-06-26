#include <numeric>
#include <vector>

class Solution {
 public:
  int maxScore(std::vector<int>& cardPoints, int k) {
    int score =
        std::accumulate(begin(cardPoints), next(begin(cardPoints), k), 0);

    int best_score = score;
    for (auto left = next(rbegin(cardPoints),
                          static_cast<int>(cardPoints.size()) - k),
              right = std::rbegin(cardPoints);
         left != rend(cardPoints); ++left, ++right) {
      score += *right - *left;
      best_score = std::max(best_score, score);
    }
    return best_score;
  }
};
