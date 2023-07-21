#include "common.h"

using namespace std;

class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int max_len = 0;
        int p = 0, q = 0;
        int zero_pos = -1;
        while (q < nums.size())
        {
            if (nums[q] == 0)
            {
                if (zero_pos == -1)
                    zero_pos = q;
                else
                {
                    p = zero_pos + 1;
                    zero_pos = q;
                }
            }
            q++;
            max_len = max(max_len, q - p);
        }
        return max_len - 1;
    }
};