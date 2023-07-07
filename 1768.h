#include "common.h"

using namespace std;

class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        int i = 0, j = 0;
        string ans(word1.size() + word2.size(), 0);
        int pos = 0;
        while (i != word1.size() || j != word2.size())
        {
            if (i < word1.size())
                ans[pos++] = word1[i++];
            if (j < word2.size())
                ans[pos++] = word2[j++];
        }
        return ans;
    }
};