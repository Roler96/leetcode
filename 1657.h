#include "common.h"

using namespace std;

class Solution
{
public:
    bool closeStrings(string word1, string word2)
    {
        if (word1.size() != word2.size())
            return false;

        map<char, int> map1, map2;
        for (int i = 0; i < word1.size(); i++)
        {
            char c1 = word1.at(i);
            char c2 = word2.at(i);
            auto it = map1.find(c1);
            if (it == map1.end())
                map1[c1] = 1;
            else
                it->second++;

            it = map2.find(c2);
            if (it == map2.end())
                map2[c2] = 1;
            else
                it->second++;
        }

        vector<int> times1, times2;
        for (auto it = map1.begin(); it != map1.end(); ++it)
        {
            char c1 = it->first;
            times1.push_back(it->second);

            int offset = std::distance(map1.begin(), it);
            auto it2 = std::next(map2.begin(), offset);

            char c2 = it2->first;
            times2.push_back(it2->second);
            if (c1 != c2)
                return false;
        }

        sort(times1.begin(), times1.end());
        sort(times2.begin(), times2.end());

        for (int i = 0; i < times1.size(); i++)
        {
            if (times1[i] != times2[i])
                return false;
        }
        return true;
    }
};