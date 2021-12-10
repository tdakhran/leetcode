class Solution {
 public:
  int numTilings(int n) {
    constexpr long modulo = 1'000'000'007;

    struct State {
      // for n = 1
      long none = 1, top = 0, bot = 0, both = 1;

      State next() const {
        return {both, (none + bot) % modulo, (none + top) % modulo,
                (top + bot + both + none) % modulo};
      }
    };
    State s;
    while (--n) {
      s = s.next();
    }

    return static_cast<int>(s.both);
  }
};
