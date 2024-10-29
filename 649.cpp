#include "common.h"

using namespace std;

class Solution
{
public:
    string predictPartyVictory(string senate)
    {
        // Radiant Dire
        string ans;
        queue<char> que;
        int flag = 0;
        int rSum = 0, dSum = 0;
        for (char c : senate)
        {
            if (flag == 0 || (flag > 0 && c == 'R') || (flag < 0 && c == 'D'))
            {
                que.push(c);
                if (c == 'R')
                    rSum++;
                else
                    dSum++;
            }
            flag += (c == 'R' ? 1 : -1);
        }

        while (rSum > 0 && dSum > 0)
        {
            char c = que.front();
            que.pop();
            if (c == 'R' && flag < 0)
                rSum--;
            else if (c == 'D' && flag > 0)
                dSum--;
            else
                que.push(c);
            flag += (c == 'R' ? 1 : -1);
        }

        if (rSum == 0)
            ans = "Dire";
        else
            ans = "Radiant";
        return ans;
    }
};