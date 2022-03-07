class Solution {
 public:
  int countOrders(int n) {
    return n == 1 ? 1
                  : (n * (2ll * n - 1) * countOrders(n - 1)) % 1'000'000'007;
  }
};
