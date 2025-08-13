#include "common.h"
#include <cassert>

using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        return solution1(n);
    }

    bool solution1(int n) {
        if (n < 3) {
            if (n == 1 || n == 3) {
                return true;
            }
            return false;
        }

        if (n % 3 != 0) {
            return false;
        }

        return solution1(n / 3);
    }

    bool solution2(int n) {

    }
};

int main() {
    Solution s;
    assert(s.isPowerOfThree(27));
    assert(s.isPowerOfThree(45) == false);
    assert(s.isPowerOfThree(26) == false);
    return 0;
}