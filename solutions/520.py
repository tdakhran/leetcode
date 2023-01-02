class Solution:

    def detectCapitalUse(self, word: str) -> bool:
        return word.isupper() or not any(c.isupper() for c in word[1:])
