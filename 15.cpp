#include "common.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) {
            return {};
        }

        
        std::sort(nums.begin(), nums.end());
        int i = 0, j = nums.size() - 1;

        auto binary_search = [](const vector<int> &vec, int num) -> bool { 
            // vec already sorted
            int i = 0, j = vec.size() - 1;
            while(i < j) {
                if (vec[i] == num || vec[j] == num) {
                    return true;
                }
                
                int mid_num = vec[(i + j) / 2];
                if (mid_num > num) {
                    j = (i + j) / 2 - 1;
                } else if (mid_num < num) {
                    i = (i + j) / 2 + 1;
                }
            }
            return false;
        };

        set<vector<int>> s;
        while(i != j) {
            int num = 0 - (nums[i] + nums[j]);
            if (binary_search(nums, num)) {
                s.insert(vector<int> {nums[i], num, nums[j]});
            }
            if (i + 1 < j) {
                num = 0 - (nums[i + 1] + nums[j]);
                if (binary_search(nums, num)) {
                    s.insert(vector<int> {nums[i + 1], num, nums[j]});
                }
            }
            if (j - 1 > i) {
                num = 0 - (nums[i] + nums[j - 1]);
                if (binary_search(nums, num)) {
                    s.insert(vector<int> {nums[i], num, nums[j - 1]});
                }
            }
            i++, j--;
        }
        return vector<vector<int>> {s.begin(), s.end()};
    }
};