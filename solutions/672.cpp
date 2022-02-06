#include <array>
#include <unordered_set>

class Solution {
 public:
  int flipLights(int n, int presses) {
    // only first 3 lamps contribute to answer
    // all possible combinations can be expressed as
    // n\p 0 1 2 3
    //   0 1 1 1 1
    //   1 1 2 2 2
    //   2 1 3 4 4
    //   3 1 4 7 8
    // let's do bfs as generic solution
    n = std::min(n, 3);
    presses = std::min(presses, 3);

    const unsigned mask = (1 << n) - 1;

    // do xor to apply operation
    std::array<unsigned, 4> operations{0b111, 0b010, 0b101, 0b001};
    std::unordered_set<unsigned> states{0b111 & mask};

    while (presses--) {
      std::unordered_set<unsigned> next_states;
      for (auto state : states) {
        for (auto operation : operations) {
          next_states.insert((state ^ operation) & mask);
        }
      }
      states = next_states;
    }
    return static_cast<int>(states.size());
  }
};
