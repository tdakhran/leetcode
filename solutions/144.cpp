/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

#include <stack>
#include <vector>

class Solution {
 public:
  std::vector<int> preorderTraversal(TreeNode *root) {
    std::stack<TreeNode *> stack({root});

    std::vector<int> result;

    while (not stack.empty()) {
      auto node = stack.top();
      stack.pop();

      if (not node) continue;

      result.push_back(node->val);
      stack.push(node->right);
      stack.push(node->left);
    }

    return result;
  }
};
