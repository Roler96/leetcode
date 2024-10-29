#include "common.h"

using namespace std;

class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        map<int, int> m;
        for (int i : arr)
        {
            auto it = m.find(i);
            if (it == m.end())
                m[i] = 1;
            else
                it->second++;
        }
        set<int> s;
        for (auto it = m.begin(); it != m.end(); ++it)
        {
            s.insert(it->second);
        }
        return s.size() == m.size();
    }
};