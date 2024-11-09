#include "common.h"
#include <cstddef>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.size() == 1) {
            return {nums};
        }
        vector<int> nums2{nums.begin() + 1, nums.end()};
        int num = nums.at(0);
        vector<vector<int>> vec = permute(nums2);
        vector<vector<int>> answer;
        for (const auto& v : vec) {
            for (int i = 0; i <= v.size(); i++) {
                auto v2 = v;
                v2.insert(v2.begin() + i, num);
                answer.push_back(v2);
            }
        }
        return answer;
    }
};

int main() {
    vector<int> nums{1, 2, 3};
    Solution s;
    for (auto v : s.permute(nums)) {
        for (auto n : v) {
            cout << n << " ";
        }
        cout << endl;
    }
    return 0;
}