#include "common.h"

using namespace std;

class Solution
{
public:
    int compress(vector<char> &chars)
    {
        int sum = 1;
        char c = chars[0];
        int index = 0;
        for (int i = 1; i < chars.size(); i++)
        {
            if (chars[i] == c)
                sum++;
            else
            {
                chars[index++] = c;
                c = chars[i];
                if (sum > 1)
                {
                    string s = std::to_string(sum);
                    for (int j = 0; j < s.size(); j++)
                        chars[index++] = s[j];
                }
                sum = 1;
            }
        }
        chars[index++] = c;
        if (sum > 1)
        {
            string s = std::to_string(sum);
            for (int j = 0; j < s.size(); j++)
                chars[index++] = s[j];
        }
        chars.resize(index);
        return index;
    }
};