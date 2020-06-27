// 无重复字符的最长子串

class Solution {
public:
    int lengthOfLongestSubstring(const string& s) {
        int stringSize = s.size();
        if (stringSize <= 1) {
            return stringSize;
        }
        std::unordered_map<char, int> charPosMap;
        int beginPos = 0;
        int endPos = 0;
        int maxSize = 0;
        int tmpSize = 0;
        for (int pos = 0; pos != stringSize; ++pos) {
            if (stringSize - beginPos <= maxSize) {
                break;
            }
            if (charPosMap.find(s[pos]) != charPosMap.end()) {
                beginPos = beginPos > charPosMap[s[pos]] + 1 ? beginPos : charPosMap[s[pos]] + 1;
                endPos = pos;
                charPosMap[s[pos]] = pos;
            } else {
                charPosMap[s[pos]] = pos;
                endPos = pos;
            }
            tmpSize = endPos - beginPos + 1;
            if (maxSize < tmpSize) {
                maxSize =  tmpSize;
            }
        }
        return maxSize;
    }
};
