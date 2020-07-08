// 整数反转

#include <cmath>

class Solution {
public:
    int reverse(int x) {
        bool isNegative = false;
        int64_t moreX = x;
        if (x < 0) {
            moreX = -moreX;
            isNegative = true;
        }
        int64_t result = 0;
        while (moreX != 0) {
            result = result * 10 + moreX % 10;
            moreX /= 10;
        }
        if (isNegative) {
            result = -result;
        }
        if (result < -pow(2, 31) || result > pow(2, 31) - 1) {
            return 0;
        }
        return result;
    }
};
