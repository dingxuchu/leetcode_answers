// 盛水最多的容器


class Solution {
public:
    int maxArea(const vector<int>& height) {
        int maxAreaNum = 0;
        int newAreaNum = 0;
        auto endSize = height.size() - 1;
        auto beginSize = 0;
        while (beginSize != endSize) {
            newAreaNum = CalAreaNum(height, beginSize, endSize);
            if (newAreaNum > maxAreaNum) {
                maxAreaNum = newAreaNum;
            }
            if (height[beginSize] >= height[endSize]) {
                --endSize;
            } else {
                ++beginSize;
            }
        }
        return maxAreaNum;
    }

    int CalAreaNum(const vector<int>& height, size_t beginSize, size_t endSize)
    {
        return (endSize - beginSize) * (height[beginSize] <= height[endSize] ? height[beginSize] : height[endSize]);
    }
};