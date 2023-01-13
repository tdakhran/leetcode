#include <functional>
#include <string>
#include <vector>

class Solution {  // NOLINT
  class Max2Keeper_t {
   public:
    void push(int Value) {
      if (Value > mBigger) {
        mSmaller = mBigger;
        mBigger = Value;
      } else if (Value > mSmaller)
        mSmaller = Value;
    }

    int sum() const { return mBigger + mSmaller; }
    int max() const { return mBigger; }

   private:
    int mBigger = 0;
    int mSmaller = 0;
  };

 public:
  int longestPath(std::vector<int>& Parent, std::string S) {
    std::vector<std::vector<size_t>> Children(S.size());

    for (size_t I = 1; I < Parent.size(); ++I)
      Children[static_cast<size_t>(Parent[I])].push_back(I);

    std::function<std::pair<int, int>(size_t)> dfs =  // NOLINT
        [&](size_t Vertex) -> std::pair<int, int> {
      int GlobalLongest = 1;

      Max2Keeper_t Keeper;

      for (auto Child : Children[Vertex]) {
        auto [gre, lre] = dfs(Child);
        GlobalLongest = std::max(GlobalLongest, gre);
        if (S[Child] != S[Vertex]) {
          Keeper.push(lre);
        }
      }

      GlobalLongest = std::max(GlobalLongest, Keeper.sum() + 1);

      return {GlobalLongest, 1 + Keeper.max()};
    };

    return dfs(0).first;
  }
};
