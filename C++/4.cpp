// 寻找两个正序数组中的中位数


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.empty()) {
            return findMedianFromSingleArray(nums2);
        }
        if (nums2.empty()) {
            return findMedianFromSingleArray(nums1);
        }
        auto nums1Size = nums1.size();
        auto nums2Size = nums2.size();
        auto sumSize = nums1Size + nums2Size;
        int midSize = sumSize / 2;
        bool isAverage = sumSize % 2 == 0;
        if (isAverage) {
            midSize -= 1;
        }
        auto nums1Begin = nums1.begin();
        auto nums2Begin = nums2.begin();
        int findPos = 0;
        double midResult = 0;
        int nextElement = 0;
        while (nums1Begin != nums1.end() || nums2Begin != nums2.end()) {
            if (nums1Begin == nums1.end()) {
                nextElement = *nums2Begin;
                ++nums2Begin;
            } else if (nums2Begin == nums2.end()) {
                nextElement = *nums1Begin;
                ++nums1Begin;
            } else {
                if (*nums1Begin <= * nums2Begin) {
                    nextElement = *nums1Begin;
                    ++nums1Begin;
                } else {
                    nextElement = *nums2Begin;
                    ++nums2Begin;
                }
            }
            if (findPos >= midSize) {
                if (findPos == midSize) {
                    midResult = nextElement;
                }
                if (!isAverage) {
                    break;
                }
                if (findPos == midSize + 1) {
                    midResult = (midResult + nextElement) / 2;
                    break;
                }
            }
            ++findPos;
        }
        return midResult;
    }

    double findMedianFromSingleArray(vector<int>& nums)
    {
        auto numsSize = nums.size();
        int midSize = numsSize / 2;
        if (numsSize % 2 == 0) {
            midSize -= 1;
        }
        double midResult = nums[midSize];
        if (numsSize % 2 == 0) {
            midResult = (midResult + nums[midSize + 1]) / 2;
        }
        return midResult;
    }
};
