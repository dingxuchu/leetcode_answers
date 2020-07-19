// 罗马数字转整数

#include <string>
class Solution {
public:
    int romanToInt(const string& s) {
        int result = 0;
        auto sSize = s.size();
        size_t pos = 0;
        AddOther(s, sSize, result, pos, 'M', ' ', ' ');
        AddOther(s, sSize, result, pos, 'C', 'D', 'M');
        AddOther(s, sSize, result, pos, 'X', 'L', 'C');
        AddOther(s, sSize, result, pos, 'I', 'V', 'X');
        return result;
    }
    void AddOther(const std::string& s, size_t sSize, int& result, size_t& pos, char firstChar, char fifthChar,
                  char tenthChar) {
        if (sSize - pos >= 2) {
            if (s[pos] == firstChar && s[pos + 1] == tenthChar) {
                result = result + romaDict.at(s[pos + 1]) - romaDict.at(s[pos]);
                pos += 2;
            } else if (s[pos] == firstChar && s[pos + 1] == fifthChar) {
                result = result + romaDict.at(s[pos + 1]) - romaDict.at(s[pos]);
                pos += 2;
            }
        } else if (sSize - pos == 1) {
            result += romaDict.at(s[pos]);
            pos += 1;
        }
        while (pos != sSize && (s[pos] == firstChar || s[pos] == fifthChar || s[pos] == tenthChar)) {
            result += romaDict.at(s[pos]);
            pos += 1;
        }
    }
    std::unordered_map<char, int> romaDict{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
                                           {'C', 100}, {'D', 500}, {'M', 1000}};
};