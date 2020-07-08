// 最长回文子串

#include <string>

class Solution {
public:
    string longestPalindrome(const string& s) {
        auto sSize = s.size();
        if (sSize <= 1) {
            return s;
        }
        std::string resultString;
        size_t maxSize = 1;
        resultString.push_back(s[0]);
        for (size_t i = 0; i != sSize; ++i) {
            if (2 * (sSize - 1 - i) < maxSize) {
                break;
            }
            FindCenterLongestPalindrome(sSize, i, s, resultString, maxSize, true);
            FindCenterLongestPalindrome(sSize, i, s, resultString, maxSize, false);
        }
        return resultString;
    }

    void FindCenterLongestPalindrome(const size_t& sSize, size_t i, const std::string& s, std::string& resultString,
            size_t& maxSize, bool isCenter)
    {
        size_t begin = i;
        size_t end = i;
        bool isEnd = false;
        if (isCenter) {
            if (end == sSize - 1) {
                return;
            } else {
                ++end;
            }
        }
        while (true) {
            if (s[begin] == s[end]) {
                if (begin == 0 || end == sSize - 1) {
                    isEnd = true;
                    break;
                }
                --begin;
                ++end;
                continue;
            }
            break;
        }
        size_t newMaxSize = 0;
        if (begin == end) {
            newMaxSize = 0;
        } else {
            if (isEnd) {
                newMaxSize = end - begin + 1;
            } else {
                newMaxSize = end - begin - 1;
            }
        }
        if (newMaxSize > maxSize) {
            if (isEnd) {
                resultString = s.substr(begin, newMaxSize);
            } else {
                resultString = s.substr(begin + 1, newMaxSize);
            }
            maxSize = newMaxSize;
        }
    }
};
