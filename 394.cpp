#include "common.h"

using namespace std;

class Solution
{
public:
    string decodeString(string s)
    {
        string ans;
        for (char c : s)
        {
            if (c >= '0' && c <= '9')
                ans.push_back(c);
            else if (c == '[')
                ans.push_back(c);
            else if (c == ']')
            {
                string str;
                while (ans.back() != '[')
                {
                    str.push_back(ans.back());
                    ans.pop_back();
                }
                ans.pop_back(); //'['
                int num = 0;
                int k = 1;
                while (!ans.empty() && ans.back() >= '0' && ans.back() <= '9')
                {
                    num += (ans.back() - '0') * k;
                    k *= 10;
                    ans.pop_back();
                }
                reverse(str.begin(), str.end());
                for (int i = 0; i < num; i++)
                    ans.append(str);
            }
            else
                ans.push_back(c);
        }
        return ans;
    }
};