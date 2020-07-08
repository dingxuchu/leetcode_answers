// Z字形变换

class Solution {
public:
    string convert(const string& s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        std::string resultString;
        size_t oneLine = 2 * numRows - 2;
        size_t numRowsMinisOne = numRows - 1;
        auto sSize = s.size();
        for (int i = 0; i != numRows; ++i) {
            if (i == 0 || i == numRows - 1) {
                for (size_t pos = i; pos < sSize; pos = pos + oneLine) {
                    resultString.push_back(s[pos]);
                }
            } else {
                size_t pos = i;
                while (pos < sSize) {
                    resultString.push_back(s[pos]);
                    size_t oneNum = pos % oneLine;
                    if (oneNum < numRowsMinisOne) {
                        pos = pos + 2 * (numRowsMinisOne - oneNum);
                    } else {
                        pos = pos + 2 * (oneLine - oneNum);
                    }
                }
            }
        }
        return resultString;
    }
};