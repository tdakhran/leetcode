from typing import List


class Solution:

    def countPrefixes(self, words: List[str], s: str) -> int:
        return len([prefix for prefix in words if s.startswith(prefix)])
