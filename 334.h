#include "common.h"

using namespace std;

class Solution
{
public:
    // T:O(n),S:O(1)
    bool increasingTriplet(vector<int> &nums)
    {
        vector<int> max_vec(nums.size());
        max_vec.back() = INT32_MIN;
        for (int i = max_vec.size() - 2; i >= 0; i--)
            max_vec[i] = max(max_vec[i + 1], nums[i + 1]);

        vector<int> min_vec(nums.size());
        min_vec[0] = INT32_MAX;
        for (int i = 1; i < min_vec.size(); i++)
            min_vec[i] = min(min_vec[i - 1], nums[i - 1]);

        for (int i = 1; i < nums.size() - 1; i++)
            if (min_vec[i] < nums[i] && nums[i] < max_vec[i])
                return true;
        return false;
    }
};