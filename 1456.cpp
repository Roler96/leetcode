#include "common.h"

using namespace std;

class Solution
{
public:
    int maxVowels(string s, int k)
    {
        auto isVowel = [](char c)
        {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                return true;
            return false;
        };

        int ans = 0;
        int count = 0;
        for (int i = 0; i < k; i++)
            if (isVowel(s[i]))
                count++;
        ans = max(ans, count);
        for (int i = k; i < s.size(); i++)
        {
            if (isVowel(s[i - k]))
                count--;
            if (isVowel(s[i]))
                count++;
            ans = max(ans, count);
        }
        return ans;
    }
};