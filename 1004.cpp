#include "common.h"

using namespace std;

class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int ans = 0;
        int p = 0, q = 0;
        while (q < nums.size())
        {
            if (nums[q] == 0)
            {
                if (k > 0)
                    k--;
                else
                {
                    int i = p;
                    for (; i < q; i++)
                    {
                        if (nums[i] == 0)
                        {
                            k++;
                            break;
                        }
                    }
                    if (k == 0)
                        p = q + 1;
                    else
                    {
                        p = i + 1;
                        k--;
                    }
                }
            }
            q++;
            ans = max(ans, q - p);
        }
        return ans;
    }
};
