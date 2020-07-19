// 正则表达式匹配

#include <string>
#include <vector>

class Solution {
public:
    bool isMatch(const string& s, const string& p) {
        size_t sSize = s.size();
        size_t pSize = p.size();
        std::vector<std::vector<bool>> result(sSize + 1, std::vector<bool>(pSize + 1, false));
        result[0][0] = true;
        for (size_t i = 0; i <= sSize; ++i) {
            for (size_t j = 1; j <= pSize; ++j) {
                if (p[j - 1] == '*') {
                    result[i][j] = result[i][j] || result[i][j - 2];
                    if (IsMatch(s, p, i, j - 1)) {
                        result[i][j] = result[i][j] || result[i - 1][j];
                    }
                } else {
                    if (IsMatch(s, p, i, j)) {
                        result[i][j] = result[i][j] || result[i - 1][j - 1];
                    }
                }
            }
        }
        return result[sSize][pSize];
    }
    bool IsMatch(const string& s, const string& p, size_t i, size_t j) {
        if (i == 0) {
            return false;
        }
        if (p[j - 1] == '.') {
            return true;
        }
        return s[i - 1] == p[j - 1];
    }
};