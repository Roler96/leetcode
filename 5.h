#include "common.h"

using namespace std;

class Solution {
public:
  string longestPalindrome(string s) {
    string result;
    result.push_back(s.at(0));
    for (int i = 1; i < s.size(); i++) {
      if (i - 1 >= 0 && s.at(i) == s.at(i - 1)) {
        int leftIndex = i - 1, rightIndex = i;
        while (s.at(leftIndex) == s.at(rightIndex)) {
          leftIndex--;
          rightIndex++;
          if (leftIndex < 0 || rightIndex >= s.size() ||
              s.at(leftIndex) != s.at(rightIndex)) {
            leftIndex++;
            rightIndex--;
            break;
          }
        }
        if (result.size() < rightIndex - leftIndex + 1) {
          result.clear();
          result = s.substr(leftIndex, rightIndex - leftIndex + 1);
        }
      }

      if (i - 1 >= 0 && i + 1 < s.size() && s.at(i - 1) == s.at(i + 1)) {
        int leftIndex = i - 1, rightIndex = i + 1;
        while (s.at(leftIndex) == s.at(rightIndex)) {
          leftIndex--;
          rightIndex++;
          if (leftIndex < 0 || rightIndex >= s.size() ||
              s.at(leftIndex) != s.at(rightIndex)) {
            leftIndex++;
            rightIndex--;
            break;
          }
        }
        if (result.size() < rightIndex - leftIndex + 1) {
          result.clear();
          result = s.substr(leftIndex, rightIndex - leftIndex + 1);
        }
      }
    }
    return result;
  }

  string longestPalindrome_dp(string s) {
    if (s.size() < 2)
      return s;
    int n = s.size();
    vector<vector<bool>> dp(n, vector<bool>(n));

    for (int i = 0; i < n; i++) {
      dp[i][i] = true;
    }
    int begin, len = 0;
    for (int L = 2; L < n; L++) {
      for (int i = 0; i < n; i++) {
        // j - i + 1 = L
        int j = L + i - 1;
        if (j >= n)
          break;

        if (s[i] != s[j])
          dp[i][j] = false;
        else {
          if (L == 2)
            dp[i][j] = true;
          else
            dp[i][j] = dp[i + 1][j - 1];
        }

        if (dp[i][j] && L > len) {
          begin = i;
          len = L;
        }
      }
    }
    return s.substr(begin, len);
  }
};
