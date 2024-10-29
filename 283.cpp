#include "common.h"

using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int pos = 0, cur = 0;
        while (pos != nums.size())
        {
            if (nums[pos] != 0)
            {
                nums[cur] = nums[pos];
                cur++;
            }
            pos++;
        }
        while (cur != nums.size())
        {
            nums[cur] = 0;
            cur++;
        }
    }

    // void moveZeroes(vector<int> &nums)
    // {
    //     vector<int> zeroPos;
    //     int size = nums.size();
    //     for (int i = 0; i < size; i++)
    //     {
    //         if (nums[i] == 0)
    //             zeroPos.push_back(i);
    //         else
    //         {
    //             if (!zeroPos.empty())
    //             {
    //                 int pos = zeroPos.front();
    //                 zeroPos.erase(zeroPos.begin());
    //                 nums[pos] = nums[i];
    //                 nums[i] = 0;
    //                 zeroPos.push_back(i);
    //             }
    //         }
    //     }
    // }
};