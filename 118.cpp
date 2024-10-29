#include "common.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for (int i = 0; i < numRows; i++) {
            if (i == 0) {
                ans.push_back(vector<int>{1});
            } else if(i == 1) {
                ans.push_back(vector<int>{1, 1});
            } else {
                const vector<int> &vec = ans[i - 1];
                vector<int> v(vec.size() + 1, 1);
                for (int j = 1; j < v.size() - 1; j++) {
                    v[j] = vec[j - 1] + vec[j];
                }
                ans.push_back(v);
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    auto vv = s.generate(5);
    for (auto vec : vv) {
        for (auto num : vec) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}