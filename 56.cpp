#include "common.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> answer;
        while(!intervals.empty()) {
            auto vec = intervals.back();
            intervals.pop_back();
            bool add = true;
            for (auto &interval : intervals) {
                if (vec[0] >= interval[0] && vec[0] <= interval[1]) {
                    interval[1] = std::max(vec[1], interval[1]);
                    add = false;
                    break;
                }
                if (vec[1] >= interval[0] && vec[1] <= interval[1]) {
                    interval[0] = std::min(vec[0], interval[0]);
                    add = false;
                    break;
                }
                if (interval[0] >= vec[0] && interval[0] <= vec[1]) {
                    interval[0] = std::min(vec[0], interval[0]);
                    interval[1] = std::max(vec[1], interval[1]);
                    add = false;
                    break;
                }
                if (interval[1] >= vec[0] && interval[1] <= vec[1]) {
                    interval[0] = std::min(vec[0], interval[0]);
                    interval[1] = std::max(vec[1], interval[1]);
                    add = false;
                    break;
                }
            }
            if (add) {
                answer.push_back(vec);
            }
        }
        return answer;
    }
};

int main() {
    Solution s;
    vector<vector<int>> intervals{{ 1,  4}, 
                                  { 0,  5}};
    vector<vector<int>> answer = s.merge(intervals);
    for (const vector<int> &vec : answer) {
        cout << "[" << vec[0] << " " << vec[1] << "]" << endl;
    }
    cout << endl;
    return 0;
}
