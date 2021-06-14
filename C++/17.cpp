// 电话号码的字母组合

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(const string& digits) {
        vector<string> resultVector;
        map<char, string> numToCharMap;
        numToCharMap.insert({'2', "abc"});
        numToCharMap.insert({'3', "def"});
        numToCharMap.insert({'4', "ghi"});
        numToCharMap.insert({'5', "jkl"});
        numToCharMap.insert({'6', "mno"});
        numToCharMap.insert({'7', "pqrs"});
        numToCharMap.insert({'8', "tuv"});
        numToCharMap.insert({'9', "wxyz"});
        vector<string> tempResult;
        for (auto digit : digits) {
            if (digit == '2') {
                tempResult.emplace_back("abc");
            } else if (digit == '3') {
                tempResult.emplace_back("def");
            } else if (digit == '4') {
                tempResult.emplace_back("ghi");
            } else if (digit == '5') {
                tempResult.emplace_back("jkl");
            } else if (digit == '6') {
                tempResult.emplace_back("mno");
            } else if (digit == '7') {
                tempResult.emplace_back("pqrs");
            } else if (digit == '8') {
                tempResult.emplace_back("tuv");
            } else {
                tempResult.emplace_back("wxyz");
            }
        }
        vector<string> beginVector;
        for (const auto& temp : tempResult) {
            if (resultVector.empty()) {
                for (auto tempValue : temp) {
                    std::string beginString;
                    beginString.push_back(tempValue);
                    resultVector.emplace_back(beginString);
                }
            } else {
                beginVector.clear();
                beginVector.insert(beginVector.begin(), resultVector.begin(), resultVector.end());
                resultVector.clear();
                for (auto tempValue : temp) {
                    for (const auto& beginValue : beginVector) {
                        resultVector.push_back(beginValue + tempValue);
                    }
                }
            }
        }
        return resultVector;
    }
};