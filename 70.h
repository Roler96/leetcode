#include "common.h"

using namespace std;

class Solution {
public:
  int climbStairs(int n) {
    auto Cab = [](int a, int b) -> int {
      int n = b;
      vector<int> vecA, vecB;
      vecA.resize(n);
      vecB.resize(n);
      for (int i = 0; i < n; i++) {
        vecA[i] = a--;
        vecB[i] = b--;
      }
      vecA.reserve(n);
      vecB.reserve(n);
      unsigned long long result = 1;
      for (int i = 0; i < n; i++) {
        result *= vecA[i];
        for (auto it = vecB.begin(), itEnd = vecB.end(); it != itEnd; ++it) {
          if (result % *it == 0) {
            result /= *it;
            vecB.erase(it);
            break;
          }
        }
      }
      for (int i = 0; i < vecB.size(); i++)
        result /= vecB[i];
      return result;
    };

    int result = 1;
    for (int numOf2 = 1; numOf2 <= n / 2; numOf2++) {
      int numOf1 = n - numOf2 * 2;
      if (numOf1 == 0)
        result += 1;
      else
        result += Cab(numOf1 + numOf2, numOf2);
    }
    return result;
  }

  int climbStairs_dp(int n) {
    if (n <= 2)
      return n;

    vector<int> dp(n);
    dp[0] = 1;
    dp[1] = 2;
    for (int i = 2; i < n; i++) {
      dp[i] = dp[i - 2] + dp[i - 1];
    }
    return dp[n - 1];
  }
};
