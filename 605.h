#include "common.h"

using namespace std;

class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        vector<bool> flags(flowerbed.size(), true);
        for (int i = 0; i < flowerbed.size(); i++)
        {
            if (flowerbed[i] == 1)
            {
                flags[i] = false;
                if (i - 1 >= 0)
                    flags[i - 1] = false;
                if (i + 1 < flowerbed.size())
                    flags[i + 1] = false;
            }
        }
        int count = 0;
        for (int i = 0; i < flags.size(); i++)
        {
            if (flags[i] == 1)
            {
                count++;
                i++; // next will be skip
            }
        }
        return count >= n;
    }
};
