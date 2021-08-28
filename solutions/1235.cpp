#include <algorithm>
#include <queue>
#include <vector>

class Solution {
  struct Job {
    int start;
    int end;
    int profit;
  };

 public:
  int jobScheduling(std::vector<int>& startTime, std::vector<int>& endTime,
                    std::vector<int>& profit) {
    std::vector<Job> jobs;
    for (size_t i = 0; i < startTime.size(); ++i) {
      jobs.push_back({startTime[i], endTime[i], profit[i]});
    }
    std::sort(begin(jobs), end(jobs),
              [](const Job& a, const Job& b) { return a.start < b.start; });

    std::queue<std::pair<int, int>> q;
    q.push({0, 0});

    int result = 0;

    for (const auto& [start, end, profit] : jobs) {
      int max_profit_by_start = 0;
      auto qsize = q.size();
      while (qsize--) {
        const auto [timepoint, profit_at_timepoint] = q.front();
        q.pop();

        if (timepoint <= start and max_profit_by_start < profit_at_timepoint) {
          max_profit_by_start = profit_at_timepoint;
        }
        if (timepoint >= start) {
          q.push({timepoint, profit_at_timepoint});
        }
      }
      q.push({start, max_profit_by_start});
      q.push({end, max_profit_by_start + profit});
      result = std::max(result, max_profit_by_start + profit);
    }
    return result;
  }
};
