#include <algorithm>
#include <vector>

class Solution {
 public:
  bool canAttendMeetings(std::vector<std::vector<int>>& intervals) {
    std::sort(begin(intervals), end(intervals));
    for (size_t pos = 1; pos < intervals.size(); ++pos) {
      if (intervals[pos][0] < intervals[pos - 1][1]) {
        return false;
      }
    }
    return true;
  }
};
