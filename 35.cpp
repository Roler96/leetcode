#include "common.h"

using namespace std;

class Solution {
public:
    int binarySearch(vector<int>& nums, int i, int j, int target) {
        if (i == j) {
            if (nums[i] == target) {
                return i;
            } else if (nums[i] < target) {
                return i + 1;
            } else {
                return i;
            }
        }

        if (nums[i] >= target) {
            return i;
        }

        if (nums[j] == target) {
            return j;
        } else if (nums[j] < target) {
            return j + 1;
        }

        int mid = (i + j) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] > target) {
            return binarySearch(nums, i, mid - 1, target);
        } else {
            return binarySearch(nums, mid + 1, j, target);
        }
    }

    int searchInsert(vector<int>& nums, int target) {
        return binarySearch(nums, 0, nums.size() - 1, target);
    }
};

int main() {
    vector<int> nums {1, 3};
    int target = 0;
    Solution s;
    cout << s.searchInsert(nums, target) << endl;
    return 0;
}