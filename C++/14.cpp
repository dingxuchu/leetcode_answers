// 最长公共前缀

#include <string>
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        std::string result;
        if (strs.empty()) {
            return result;
        }
        result = strs[0];
        size_t strsSize = strs.size();
        for (size_t pos = 1; pos != strsSize; ++pos) {
            UpdateResult(strs[pos], result);
            if (result.empty()) {
                break;
            }
        }
        return result;
    }

    void UpdateResult(const std::string& nextString, std::string& result)
    {
        size_t compareSize = nextString.size() > result.size() ? result.size() : nextString.size();
        size_t resultSize = 0;
        for (; resultSize != compareSize; ++resultSize) {
            if (nextString[resultSize] != result[resultSize]) {
                break;
            }
        }
        if (resultSize != result.size()) {
            result = result.substr(0, resultSize);
        }
    }
};