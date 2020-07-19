// 整数转罗马数字

#include <string>

class Solution {
public:
    string intToRoman(int num) {
        std::string resultString;
        int nextResult = 0;
        nextResult = num / 1000;
        UpdateResultString(resultString, ' ', ' ', 'M', nextResult);
        num = num % 1000;
        nextResult = num / 100;
        UpdateResultString(resultString, 'M', 'D', 'C', nextResult);
        num = num % 100;
        nextResult = num / 10;
        UpdateResultString(resultString, 'C', 'L', 'X', nextResult);
        num = num % 10;
        nextResult = num;
        UpdateResultString(resultString, 'X', 'V', 'I', nextResult);
        return resultString;
    }
    void UpdateResultString(std::string& resultString, char tenthChar,char fifthChar, char firstChar, int nextResult) {
        if (nextResult == 9) {
            resultString.push_back(firstChar);
            resultString.push_back(tenthChar);
        } else if (nextResult == 4) {
            resultString.push_back(firstChar);
            resultString.push_back(fifthChar);
        } else if (nextResult >= 5) {
            resultString.push_back(fifthChar);
            for (int i = 0; i != nextResult - 5; ++i) {
                resultString.push_back(firstChar);
            }
        } else {
            for (int i = 0; i != nextResult; ++i) {
                resultString.push_back(firstChar);
            }
        }
    }
};