#include <unordered_map>
#include <vector>

class Solution {
 public:
  int maximumUniqueSubarray(std::vector<int>& nums) {
    int result = 0;
    for (struct {
           int get_unique_sum(const std::vector<int>& nums) {
             for (auto it = last_pos_.find(nums[right_]);
                  it != end(last_pos_) and left_ <= it->second;
                  sum_ -= nums[left_], ++left_) {
             }
             last_pos_[nums[right_]] = right_;
             sum_ += nums[right_];
             return sum_;
           }

           void operator++() { ++right_; }

           bool valid(const std::vector<int>& nums) const {
             return right_ < nums.size();
           }

          private:
           size_t left_ = 0, right_ = 0;
           std::unordered_map<int, size_t> last_pos_;
           int sum_ = 0;
         } state;
         state.valid(nums); ++state) {
      result = std::max(result, state.get_unique_sum(nums));
    }
    return result;
  }
};
