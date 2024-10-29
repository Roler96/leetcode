#include "common.h"

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }

        if (nums.size() == 2)  {
            return std::max(nums[0], nums[1]); 
        }

        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = std::max(nums[0], nums[1]);

        for (int i = 2; i < nums.size(); i++) {
            dp[i] = std::max(nums[i] + dp[i - 2], dp[i - 1]);
        }

        auto maxIt = std::max_element(dp.begin(), dp.end());
        return *maxIt;
    }
};

int main() {
    vector<int> nums {2, 7, 9, 3, 1};
    Solution s;
    cout << s.rob(nums);
    return 0;
}