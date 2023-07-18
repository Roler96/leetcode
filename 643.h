#include "common.h"

using namespace std;

class Solution
{
public:
    // 1 <= k <= n <= 1e5
    double findMaxAverage(vector<int> &nums, int k)
    {
        double ans = -1e9;
        double sum = 0;
        for (int i = 0; i < k; i++)
            sum += nums[i];
        ans = max(ans, sum / k);
        int pos = k;
        while (pos < nums.size())
        {
            sum += nums[pos];
            sum -= nums[pos - k];
            ans = max(ans, sum / k);
            pos++;
        }
        return ans;
    }
};