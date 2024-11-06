#include "common.h"

using namespace std;

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBSTImpl(nums, 0, nums.size() - 1);
    }

    TreeNode* sortedArrayToBSTImpl(vector<int>& nums, int i, int j) {
        if (i == j) {
            return new TreeNode(nums[i], nullptr, nullptr);
        }
        if (i + 1 == j) {
            return new TreeNode(nums[j], new TreeNode(nums[i]), nullptr);
        }

        int mid = (i + j + 1) / 2;
        return new TreeNode(nums[mid], sortedArrayToBSTImpl(nums, i, mid - 1), sortedArrayToBSTImpl(nums, mid + 1, j));
    }
};