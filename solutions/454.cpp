#include <unordered_map>
#include <vector>

class Solution {
 public:
  int fourSumCount(std::vector<int>& A, std::vector<int>& B,
                   std::vector<int>& C, std::vector<int>& D) {
    std::unordered_map<int, int> AB;
    for (auto a : A) {
      for (auto b : B) {
        ++AB[a + b];
      }
    }
    int result = 0;
    for (auto c : C) {
      for (auto d : D) {
        if (auto it = AB.find(-(c + d)); it != end(AB)) {
          result += it->second;
        }
      }
    }
    return result;
  }
};
