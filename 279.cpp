#include "common.h"

using namespace std;

/*
给你一个整数 n ，返回 和为 n 的完全平方数的最少数量 。1 <= n <= 10^4

完全平方数 是一个整数，其值等于另一个整数的平方；换句话说，其值等于一个整数自乘的积。
例如，1、4、9 和 16 都是完全平方数，而 3 和 11 不是。
*/

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 10, 0);
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            int min = dp[i - 1] + 1;
            int num = 1;
            while(num * num <= i) {
                if (num * num == i) {
                    min = 1;
                    break;
                }
                int index = num * num;
                min = std::min(min, dp[index] + dp[i - index]);
                num++;
            }
            dp[i] = min;
        }
        return dp[n];
    }
};

int main() {
    Solution s;
    cout << s.numSquares(12) << endl;
    return 0;
}