#include "common.h"

using namespace std;

class Solution
{
public:
    string reverseVowels(string s)
    {
        vector<int> vecIndex;
        vector<char> vecChar;
        set<char> vowels({'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'});
        for (int i = 0; i < s.size(); i++)
        {
            if (vowels.find(s[i]) != vowels.end())
            {
                vecIndex.push_back(i);
                vecChar.push_back(s[i]);
            }
        }

        for(int i = 0; i < vecIndex.size(); i++)
        {
            int index = vecIndex[i];
            char c = vecChar[vecChar.size() - 1 - i];
            s[index] = c;
        }
        return s;
    }
};