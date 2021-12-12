#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
 public:
  std::vector<int> distanceK(TreeNode *root, TreeNode *target, int k) {
    std::unordered_map<TreeNode *, TreeNode *> parent;

    std::queue<TreeNode *> queue;
    queue.push(root);

    while (not queue.empty()) {
      auto node = queue.front();
      queue.pop();

      for (auto ch : {node->left, node->right}) {
        if (ch) {
          parent[ch] = node;
          queue.push(ch);
        }
      }
    }

    queue.push(target);
    std::unordered_set<TreeNode *> visited{target};

    for (int level = 0; level < k and not queue.empty(); ++level) {
      auto qsize = queue.size();
      while (qsize--) {
        auto node = queue.front();
        queue.pop();

        for (auto ch : {node->left, node->right}) {
          if (ch and visited.insert(ch).second) {
            queue.push(ch);
          }
        }
        if (auto it = parent.find(node);
            it != end(parent) and visited.insert(it->second).second) {
          queue.push(it->second);
        }
      }
    }

    std::vector<int> result;
    while (not queue.empty()) {
      result.push_back(queue.front()->val);
      queue.pop();
    }
    return result;
  }
};
