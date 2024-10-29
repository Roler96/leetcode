#include "common.h"

using namespace std;

class Solution
{
public:
    // 1 <= str1.length, str2.length <= 1000
    string gcdOfStrings(string str1, string str2)
    {
        if (str1.size() < str2.size())
            swap(str1, str2);
        while (str1.size() % str2.size() != 0)
        {
            if (str1.substr(0, str2.size()) != str2)
                return "";
            string str = str1.substr(str2.size(), str1.size() - str2.size());
            str1 = str2;
            str2 = str;
            if (str1.size() < str2.size())
                swap(str1, str2);
        }
        string str;
        for (int i = 0; i < str1.size() / str2.size(); i++)
            str += str2;
        if (str1 == str)
            return str2;
        else
            return "";
    }
};
