#include "common.h"

using namespace std;

class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        if (nums.empty())
            return -1;
        int left_sum = 0;
        int right_sum = accumulate(nums.begin(), nums.end(), 0) - nums[0];
        for (int i = 0; i < nums.size(); i++)
        {
            if (left_sum == right_sum)
                return i;
            left_sum += nums[i];
            if (i + 1 < nums.size())
                right_sum -= nums[i + 1];
        }
        return -1;
    }
};