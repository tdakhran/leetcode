class Solution:

    def wordPattern(self, pattern: str, s: str) -> bool:
        words = s.split(' ')
        return len(words) == len(pattern) and all(
            len(k) == len(set(k))
            for k in list(zip(*set(zip(pattern, words)))))
