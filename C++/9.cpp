// 回文数

#include <string>
#include <algorithm>

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        std::string oneString = std::to_string(x);
        std::string twoString(oneString);
        std::reverse(twoString.begin(), twoString.end());
        return oneString == twoString;
    }
};