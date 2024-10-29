#include "common.h"

using namespace std;

class Solution
{
public:
    int largestAltitude(vector<int> &gain)
    {
        int ans = 0;
        int current_altitude = 0;
        for (int i = 0; i < gain.size(); i++)
        {
            current_altitude += gain[i];
            ans = max(ans, current_altitude);
        }
        return ans;
    }
};