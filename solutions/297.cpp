#include <queue>
#include <sstream>
#include <string>

class Codec {
  static inline constexpr int16_t NULL_VALUE{
      std::numeric_limits<int16_t>::max()};
  static inline constexpr const char* SEPARATOR = "#";

 public:
  std::string serialize(TreeNode* root) {
    std::queue<TreeNode*> q;
    std::string result;
    q.push(root);
    while (not q.empty()) {
      auto node = q.front();
      q.pop();

      if (!node) {
        result += std::to_string(NULL_VALUE) + SEPARATOR;
        continue;
      }

      result += std::to_string(node->val) + SEPARATOR;
      q.push(node->left);
      q.push(node->right);
    }
    return result;
  }

  TreeNode* deserialize(std::string data) {
    std::istringstream ss(data);
    char separator;
    int16_t value;

    std::queue<TreeNode*> q;
    ss >> value >> separator;
    TreeNode* result = nullptr;
    if (value != NULL_VALUE) {
      q.push(result = new TreeNode(value));
    }

    while (not q.empty()) {
      auto node = q.front();
      q.pop();
      if (ss >> value >> separator and value != NULL_VALUE) {
        q.push(node->left = new TreeNode(value));
      }
      if (ss >> value >> separator and value != NULL_VALUE) {
        q.push(node->right = new TreeNode(value));
      }
    }
    return result;
  }
};
