#include <array>
#include <string>
#include <vector>

class Solution {
 public:
  bool equationsPossible(std::vector<std::string>& equations) {
    std::array<size_t, 26> u{0};
    size_t group_index = 1;

    for (auto eq : equations) {
      auto a = static_cast<size_t>(eq.front() - 'a');
      auto b = static_cast<size_t>(eq.back() - 'a');
      if (eq[1] == '=') {
        if (u[a] and u[b]) {
          auto target_index = u[a];
          for (auto& u_i : u) {
            if (u_i == target_index) {
              u_i = u[b];
            }
          }
        } else if (u[a]) {
          u[b] = u[a];
        } else if (u[b]) {
          u[a] = u[b];
        } else {
          u[a] = u[b] = group_index++;
        }
      } else if (a == b) {
        return false;
      }
    }
    for (auto eq : equations) {
      auto a = static_cast<size_t>(eq.front() - 'a');
      auto b = static_cast<size_t>(eq.back() - 'a');
      if (eq[1] == '!') {
        if (u[a] and u[b] and u[a] == u[b]) {
          return false;
        }
      }
    }
    return true;
  }
};
