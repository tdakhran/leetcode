#include <cstdint>

class Solution {
  struct State {
    static inline constexpr int64_t modulo = 1'000'000'007;

    int64_t a = 1;
    int64_t p = 1;
    int64_t single_l = 1;
    int64_t double_l = 0;
    int64_t a_p = 0;
    int64_t a_single_l = 0;
    int64_t a_double_l = 0;

    State next() {
      return {p + single_l + double_l,
              p + single_l + double_l,
              p,
              single_l,
              a_p + a_single_l + a_double_l + a,
              a_p + a,
              a_single_l};
    }

    State &normalize() {
      a %= modulo;
      p %= modulo;
      single_l %= modulo;
      double_l %= modulo;
      a_p %= modulo;
      a_single_l %= modulo;
      a_double_l %= modulo;
      return *this;
    }

    int sum() const {
      return (a + p + single_l + double_l + a_p + a_single_l + a_double_l) %
             modulo;
    }
  };

 public:
  int checkRecord(int n) {
    State s;  // initialized for n == 1

    while (--n) {
      s = s.next().normalize();
    }
    return s.sum();
  }
};
