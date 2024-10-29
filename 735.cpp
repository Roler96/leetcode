#include "common.h"

using namespace std;

class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        vector<int> ans;
        for (int i = 0; i < asteroids.size(); i++)
        {
            int num = asteroids[i];
            if (ans.empty())
            {
                ans.push_back(num);
                continue;
            }

            int before = ans.back();
            if (before < 0 || num > 0)
            {
                ans.push_back(num);
            }
            else
            {
                if (abs(before) == abs(num))
                    ans.pop_back();
                else if (abs(before) > abs(num))
                    continue;
                else
                {
                    ans.pop_back();
                    if (ans.empty())
                        ans.push_back(num);
                    else
                        i--;
                }
            }
        }
        return ans;
    }
};