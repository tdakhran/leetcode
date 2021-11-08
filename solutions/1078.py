from typing import List


class Solution:
    def findOcurrences(self, text: str, first: str, second: str) -> List[str]:
        pprev = None
        prev = None
        result = []
        for word in text.split(' '):
            if pprev == first and prev == second:
                result.append(word)
            pprev = prev
            prev = word
        return result
