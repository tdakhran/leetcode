from itertools import takewhile, accumulate
from typing import List


class Solution:
    def maxIceCream(self, costs: List[int], coins: int) -> int:
        return len(list(takewhile(lambda v: v <= coins, accumulate(sorted(costs)))))
