#include "common.h"

using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        vector<string> words;
        bool beginWord = false;
        string str;
        for (char c : s)
        {
            if (c == ' ')
            {
                if (!beginWord)
                    continue;
                else
                    beginWord = false;
                words.push_back(str);
                str.clear();
            }
            else
            {
                if (!beginWord)
                    beginWord = true;
                str.push_back(c);
            }
        }
        // last word
        if (!str.empty())
            words.push_back(str);

        string ans;
        for (int i = words.size() - 1; i >= 0; i--)
        {
            ans.append(words[i]);
            if (i != 0)
                ans.append(" ");
        }
        return ans;
    }
};