#include "common.h"

using namespace std;

class Solution {
public:
    // 这个效率甚至不如暴力枚举
    bool searchMatrix_bad(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) {
            return false;
        }

        struct Range {
            Range(int min_, int max_): min(min_), max(max_) {}
            int min;
            int max;
        };

        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<Range> row_ranges;
        vector<Range> col_ranges;
        for (int row = 0; row < rows; row++) {
            row_ranges.push_back({matrix[row][0], matrix[row][cols - 1]});
        }
        for (int col = 0; col < cols; col++) {
            col_ranges.push_back({matrix[0][col], matrix[rows - 1][col]});
        }

        for (int row = 0; row < rows; row++) {
            const Range &row_range = row_ranges.at(row);
            if (target < row_range.min || row_range.max < target) {
                continue;
            }
            for (int col = 0; col < cols; col++) {
                const Range &col_range = col_ranges.at(col);
                if (target < col_range.min || col_range.max < target) {
                    continue;
                }
                if (matrix[row][col] == target) {
                    return true;
                }
            }
        }
        return false;
    }

    // 剪枝+二分查找
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        if (matrix.empty()) {
            return false;
        }

        int rows = matrix.size();
        int cols = matrix[0].size();

        for (int row = 0; row < rows; row++) {
            int row_min = matrix[row][0], row_max = matrix[row][cols - 1];
            if (target < row_min || row_max < target) {
                continue;
            }
            auto it = std::find(matrix[row].begin(), matrix[row].end(), target);
            if (it != matrix[row].end()) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    vector<vector<int>> matrix{{48,  65,  70,  113, 133, 163, 170, 216,  298,  389},
                               {89,  169, 215, 222, 250, 348, 379, 426,  469,  554},
                               {178, 202, 253, 294, 367, 392, 428, 434,  499,  651},
                               {257, 276, 284, 332, 380, 470, 516, 561,  657,  698},
                               {275, 331, 391, 432, 500, 595, 602, 673,  758,  783},
                               {357, 365, 412, 450, 556, 642, 690, 752,  801,  887},
                               {359, 451, 534, 609, 654, 662, 693, 766,  803,  964},
                               {390, 484, 614, 669, 684, 711, 767, 804,  857,  1055},
                               {400, 515, 683, 732, 812, 834, 880, 930,  1012, 1130},
                               {480, 538, 695, 751, 864, 939, 966, 1027, 1089, 1224}};

    Solution s;
    cout << (s.searchMatrix(matrix, 929) ? "True" : "False") << endl;
    return 0;
    }