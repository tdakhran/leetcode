#include <algorithm>
#include <numeric>
#include <vector>

class DSU {
 private:
  std::vector<int> parent;

 public:
  DSU(size_t n) {
    parent = std::vector<int>(n + 1);
    std::iota(begin(parent), end(parent), 0);
  }

  int findParent(int node) {
    auto index = static_cast<size_t>(node);
    if (parent[index] == node) {
      return node;
    }

    return parent[index] = findParent(parent[index]);
  }

  void combine(int u, int v) {
    size_t u_parent = static_cast<size_t>(findParent(u));
    size_t v_parent = static_cast<size_t>(findParent(v));

    if (u_parent != v_parent) {
      parent[u_parent] = parent[v_parent];
    }
  }
};

class Solution {
 public:
  int largestComponentSize(std::vector<int>& nums) {
    auto dsu =
        DSU(static_cast<size_t>(*std::max_element(begin(nums), end(nums))));

    for (auto val : nums) {
      for (int i = 2; i * i <= val; i++) {
        if (val % i == 0) {
          dsu.combine(val, i);
          dsu.combine(val, val / i);
        }
      }
    }

    std::unordered_map<int, int> mp;
    int result = 1;

    // count the number of parent for each value
    for (auto val : nums) {
      result = std::max(result, ++mp[dsu.findParent(val)]);
    }

    return result;
  }
};
