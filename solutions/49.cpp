#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<std::string>> groupAnagrams(
      std::vector<std::string>& strs) {
    auto hash = [](std::string s) {
      std::sort(begin(s), end(s));
      return s;
    };

    std::unordered_map<std::string, std::vector<std::string>> map;

    for (auto str : strs) {
      map[hash(str)].push_back(std::move(str));
    }
    std::vector<std::vector<std::string>> result;
    for (auto& [key, value] : map) {
      result.emplace_back(std::move(value));
    }
    return result;
  }
};
