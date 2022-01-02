#include <unordered_map>

class Logger {
  std::unordered_map<std::string, int> last;

 public:
  bool shouldPrintMessage(int timestamp, std::string message) {
    if (auto it = last.find(message);
        it != end(last) and it->second + 10 > timestamp) {
      return false;
    }

    last[message] = timestamp;
    return true;
  }
};
