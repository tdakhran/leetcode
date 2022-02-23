#include <queue>
#include <unordered_map>

class Solution {
 public:
  Node *cloneGraph(Node *node) {
    if (not node) {
      return nullptr;
    }
    std::queue<Node *> q;
    std::unordered_map<Node *, Node *> match;
    q.push(node);
    match[node] = new Node(node->val);

    while (not q.empty()) {
      auto p = q.front();
      q.pop();
      auto n = match[p];

      for (auto nei : p->neighbors) {
        if (auto it = match.find(nei); it != end(match)) {
          n->neighbors.push_back(it->second);
          continue;
        }

        n->neighbors.push_back(new Node(nei->val));
        match[nei] = n->neighbors.back();
        q.push(nei);
      }
    }
    return match[node];
  }
};
