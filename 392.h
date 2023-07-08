#include "common.h"

using namespace std;

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        if (s.empty())
            return true;
        if (s.size() > t.size())
            return false;
        int pos_s = 0, pos_t = 0;
        while (pos_t != t.size())
        {
            if (t[pos_t] == s[pos_s])
                pos_s++;
            pos_t++;
            if (pos_s == s.size())
                return true;
        }
        return false;
    }
};