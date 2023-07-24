#include "common.h"

using namespace std;

class Solution
{
public:
    int equalPairs(vector<vector<int>> &grid)
    {
        int ans = 0;
        int n = grid.size();
        map<vector<int>, int> m;
        for (int row = 0; row < n; row++)
        {
            auto it = m.find(grid[row]);
            if (it == m.end())
                m[grid[row]] = 1;
            else
                it->second++;
        }
        vector<int> vec(n);
        for (int col = 0; col < n; col++)
        {
            vec.clear();
            for (int row = 0; row < n; row++)
                vec.push_back(grid[row][col]);
            auto it = m.find(vec);
            if (it != m.end())
                ans += it->second;
        }
        return ans;
    }
};