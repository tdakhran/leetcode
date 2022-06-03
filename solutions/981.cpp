#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

class TimeMap {
  using Element = std::pair<int, std::string>;
  std::unordered_map<std::string, std::vector<Element>> m;

 public:
  TimeMap() {}

  void set(const std::string &key, const std::string &value, int timestamp) {
    m[key].push_back({timestamp, value});
  }

  std::string get(const std::string &key, int timestamp) {
    const auto &v = m[key];
    if (auto it = std::upper_bound(begin(v), end(v),
                                   Element{timestamp, std::string(1, 'z' + 1)});
        it != begin(v)) {
      return prev(it)->second;
    }
    return "";
  }
};
