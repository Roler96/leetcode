#include "common.h"

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        vector<int> answer;
        if (matrix.empty()) {
            return answer;
        }

        enum Dicrection { Up, Down, Left, Right };

        Dicrection d  = Right;
        int rows = matrix.size();
        int cols = matrix[0].size();
        int size = rows * cols;
        int row = 0, col = 0;
        int row_start = 0, row_end = rows;
        int col_start = 0, col_end = cols;
        while (answer.size() < size) {
            switch (d) {
            case Up: {
                answer.push_back(matrix[row][col]);
                row--;
                if (row < row_start) {
                    d = Right;
                    row++;
                    col++;
                    col_start++;
                }
                break;
            }
            case Down: {
                answer.push_back(matrix[row][col]);
                row++;
                if (row == row_end) {
                    d = Left;
                    row--;
                    col--;
                    col_end--;
                }
                break;
            }
            case Left: {
                answer.push_back(matrix[row][col]);
                col--;
                if (col < col_start) {
                    d = Up;
                    col++;
                    row--;
                    row_end--;
                }
                break;
            }
            case Right: {
                answer.push_back(matrix[row][col]);
                col++;
                if (col == col_end) {
                    d = Down;
                    col--;
                    row++;
                    row_start++;
                }
                break;
            }
            }
        }
        return answer;
    }
};

int main() {
    Solution s;
    vector<vector<int>> matrix{{1,2,3},{4,5,6},{7,8,9}};
    vector<int> v = s.spiralOrder(matrix);
    for (int n : v) {
        cout << n << " ";
    }
    cout << endl;
    return 0;
}