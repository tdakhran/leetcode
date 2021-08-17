# python 3

class Solution:
    @staticmethod
    def goodNodesImpl(root: TreeNode, max_observed_value: float) -> int:
        if root is None:
            return 0
        retval = int(root.val >= max_observed_value)
        max_observed_value = max(max_observed_value, root.val)
        return retval + sum([
            Solution.goodNodesImpl(child, max_observed_value)
            for child in [root.left, root.right]
        ])

    def goodNodes(self, root: TreeNode) -> int:
        return self.goodNodesImpl(root, float('-inf'))
