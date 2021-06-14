// 有效的括号

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <stack>
#include <map>

using namespace std;

class Solution {
public:
    bool isValid(const string& s) {
        stack<char> charStack;
        map<char, char> charToCharMap;
        charToCharMap[']'] = '[';
        charToCharMap[')'] = '(';
        charToCharMap['}'] = '{';
        for (auto value : s) {
            auto findIter = charToCharMap.find(value);
            if (findIter != charToCharMap.end()) {
                if (charStack.empty()) {
                    return false;
                }
                auto resultTop = charStack.top();
                charStack.pop();
                if (findIter->second != resultTop) {
                    return false;
                }
            } else {
                charStack.push(value);
            }
        }
        return charStack.empty();
    }
};

