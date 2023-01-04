from functools import reduce
from itertools import groupby
from typing import List


class Solution:

    def minimumRounds(self, tasks: List[int]) -> int:
        groups = [len(list(group)) for key, group in groupby(sorted(tasks))]
        if groups.count(1):
            return -1
        return reduce(lambda x, y: x + y // 3 + ((y % 3) != 0), groups, 0)
