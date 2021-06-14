// 最接近的三数之和

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        size_t numsSize = nums.size();
        sort(nums.begin(), nums.end());
        int finalTarget = nums[0] + nums[1] + nums[2];
        int tempValue = GetAbsValue(target - finalTarget);
        for (size_t begin = 0; begin != numsSize - 2; ++begin) {
            int tempTarget = target - nums[begin];
            size_t left = begin + 1;
            size_t right = numsSize - 1;
            while (left < right) {
                int temp = nums[left] + nums[right] - tempTarget;
                if (GetAbsValue(temp) < tempValue) {
                    finalTarget = nums[begin] + nums[left] + nums[right];
                    tempValue = GetAbsValue(temp);
                }
                if (temp > 0) {
                    right--;
                } else if (temp < 0) {
                    left++;
                } else {
                    return finalTarget;
                }
            }

        }
        return finalTarget;
    }
    int GetAbsValue(int value) {
        return value > 0 ? value : -value;
    }
};

