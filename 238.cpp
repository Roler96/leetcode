#include "common.h"

using namespace std;

class Solution
{
public:
    // O(n)
    // do not use division operation
    // 2 <= nums.length <= 105
    // -30 <= nums[i] <= 30
    vector<int> productExceptSelf(vector<int> &nums)
    {
        // get each num counts
        vector<int> counts(61, 0);
        for (int i = 0; i < nums.size(); i++)
        {
            int index = nums[i] + 30;
            counts[index]++;
        }

        vector<int> ans(nums.size());
        bool have_zero = counts[30] > 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int index = nums[i] + 30;

            if (have_zero && nums[i] != 0)
                ans[i] = 0;
            else
            {
                ans[i] = 1;
                for (int j = 0; j < counts.size(); j++)
                {
                    if (counts[j] == 0)
                        continue;
                    if (j != index)
                        ans[i] *= pow(j - 30, counts[j]);
                    else
                        ans[i] *= pow(j - 30, counts[j] - 1);
                }
            }
        }
        return ans;
    }
};