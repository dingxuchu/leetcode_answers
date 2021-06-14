//三数之和

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        size_t numsSize = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> resultThreeSum;
        for (int begin = 0; begin != numsSize; ++begin) {
            if (nums[begin] > 0) {
                break;
            }
            if (begin > 0 && nums[begin] == nums[begin - 1]) {
                continue;
            }
            size_t left = begin + 1;
            size_t right = numsSize - 1;
            while (left < right) {
                int tempTarget = nums[left] + nums[right];
                if (tempTarget > -nums[begin]) {
                    right--;
                } else if (tempTarget < -nums[begin]) {
                    left++;
                } else {
                    resultThreeSum.emplace_back(std::vector<int>{nums[begin], nums[left], nums[right]});
                    right--;
                    left++;
                    while (left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }
                    while (left < right && nums[right] == nums[right + 1]) {
                        right--;
                    }
                }
            }
        }
        return resultThreeSum;
    }
};