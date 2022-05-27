class Solution {
 public:
  int numberOfSteps(int num) {
    int steps = 0;
    for (; num; num >>= 1) {
      steps += (num & 1) + (num > 1);
    }
    return steps;
  }
};
