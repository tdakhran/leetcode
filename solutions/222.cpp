class Solution {
 public:
  int countNodes(TreeNode *root) {
    if (!root) {
      return 0;
    }
    // calculate height
    int height = 0;
    for (auto it = root; it; ++height, it = it->left) {
    }
    auto result = (1 << (height - 1)) - 1;  // <-- size without last level

    while (height-- and root) {
      int height_of_left = 0;
      for (auto it = root->left; it; ++height_of_left, it = it->right) {
      }
      if (height_of_left == height) {  // <-- check if left subtree is complete
        root = root->right;
        result += height ? (1 << (height - 1)) : 1;
      } else {
        root = root->left;
      }
    }

    return result;
  }
};
