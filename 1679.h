#include "common.h"

using namespace std;

class Solution
{
public:
    int maxOperations(vector<int> &nums, int k)
    {
        int ans = 0;
        map<int, int> m;
        for (int i = 0; i < nums.size(); i++)
        {
            int target = k - nums[i];
            auto it_target = m.find(target);
            if (it_target == m.end())
            {
                auto it = m.find(nums[i]);
                if (it == m.end())
                    m[nums[i]] = 1;
                else
                    it->second++;
            }
            else
            {
                it_target->second--;
                ans++;
                if (it_target->second == 0)
                    m.erase(it_target);
            }
        }
        return ans;
    }
};