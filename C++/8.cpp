// 字符串转换整数

#include <string>
#include <cmath>

class Solution {
public:
    int myAtoi(const std::string& str) {
        bool isNegative = false;
        std::string effectiveStr;
        auto strSize = str.size();
        size_t pos = 0;
        for (;pos != strSize; ++pos) {
            if (str[pos] == ' ') {
                continue;
            }
            if (str[pos] == '+') {
                ++pos;
                break;
            }
            if (str[pos] == '-') {
                isNegative = true;
                ++pos;
                break;
            }
            if (str[pos] <= '9' && str[pos] >= '0') {
                break;
            }
            return 0;
        }
        for (; pos != strSize; ++pos) {
            if (effectiveStr.empty() && str[pos] == '0') {
                continue;
            }
            if (str[pos] <= '9' && str[pos] >= '0') {
                effectiveStr.push_back(str[pos]);
            } else {
                break;
            }
        }
        if (effectiveStr.empty()) {
            return 0;
        }
        if (effectiveStr.size() > 10) {
            if (isNegative) {
                return static_cast<int>(-pow(2, 31));
            } else {
                return static_cast<int>(pow(2, 31) - 1);
            }
        }
        long result = std::stol(effectiveStr);
        if (isNegative) {
            result *= -1;
        }
        if (result > pow(2, 31) - 1) {
            return static_cast<int>(pow(2, 31) - 1);
        }
        if (result < -pow(2, 31)) {
            return static_cast<int>(-pow(2, 31));
        }
        return static_cast<int>(result);
    }
};