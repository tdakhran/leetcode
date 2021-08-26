class Solution:
    def isValidSerialization(self, preorder: str) -> bool:
        stack = []
        for e in preorder.split(','):
            if e == '#':
                while stack and stack[-1] == '#':
                    stack.pop()
                    if not stack:
                        return False
                    stack.pop()
            stack.append(e)
        return stack == ['#']
