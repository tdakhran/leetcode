class Solution:
    def numDecodings(self, s: str) -> int:
        if not s or s[0] == '0':
            return 0
        last = 1
        prelast = (1, 0)
        for c in s:
            new_last = 0
            if 10 <= prelast[1] * 10 + int(c) <= 26:
                new_last += prelast[0]
            if int(c):
                new_last += last
            prelast = (last, int(c))
            last = new_last
        return last
