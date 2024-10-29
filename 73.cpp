#include "common.h"

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        set<int> zeroRows, zeroCols;
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (matrix[row][col] == 0) {
                    zeroRows.insert(row);
                    zeroCols.insert(col);
                }
            }
        }
        for (int row : zeroRows) {
            for (int col = 0; col < cols; col++) {
                matrix[row][col] = 0;
            }
        }
        for (int col : zeroCols) {
            for (int row = 0; row < rows; row++) {
                matrix[row][col] = 0;
            }
        }
    }
};