#include "common.h"

using namespace std;

class Solution
{
public:
    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
    {
        vector<vector<int>> ans(2);

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int pos = 0;
        for (int i = 1; i < nums1.size(); i++)
        {
            if (nums1[i] != nums1[pos])
                nums1[++pos] = nums1[i];
        }
        if (pos != nums1.size())
            nums1.resize(pos + 1);

        pos = 0;
        for (int i = 1; i < nums2.size(); i++)
        {
            if (nums2[i] != nums2[pos])
                nums2[++pos] = nums2[i];
        }
        if (pos != nums2.size())
            nums2.resize(pos + 1);

        int p = 0, q = 0;
        while (p != nums1.size() || q != nums2.size())
        {
            if (p == nums1.size())
            {
                for (int i = q; i < nums2.size(); i++)
                    ans[1].push_back(nums2[i]);
                break;
            }

            if (q == nums2.size())
            {
                for (int i = p; i < nums1.size(); i++)
                    ans[0].push_back(nums1[i]);
                break;
            }

            if (nums1[p] == nums2[q])
            {
                p++;
                q++;
            }
            else if (nums1[p] < nums2[q])
            {
                ans[0].push_back(nums1[p]);
                p++;
            }
            else
            {
                ans[1].push_back(nums2[q]);
                q++;
            }
        }
        return ans;
    }
};