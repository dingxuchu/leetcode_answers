// 四数之和

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        std::vector<vector<int>> resultVector;
        size_t numsSize = nums.size();
        if (numsSize < 4) {
            return resultVector;
        }
        for (size_t beginSize = 0; beginSize != numsSize - 3; beginSize++) {
            if (beginSize > 0 && nums[beginSize] == nums[beginSize - 1]) {
                continue;
            }
            int threeSumTarget = target - nums[beginSize];
            auto threeSumVector = threeSum(nums, beginSize + 1, numsSize, threeSumTarget);
            for (auto& one : threeSumVector) {
                one.push_back(nums[beginSize]);
                resultVector.push_back(one);
            }
        }
        return resultVector;
    }

    vector<vector<int>> threeSum(vector<int>& nums, size_t begin, size_t numsSize, int target) {
        vector<vector<int>> resultThreeSum;
        for (auto threeBegin = begin; threeBegin != numsSize; ++threeBegin) {
            if (threeBegin > begin && nums[threeBegin] == nums[threeBegin - 1]) {
                continue;
            }
            size_t left = threeBegin + 1;
            size_t right = numsSize - 1;
            while (left < right) {
                int tempTarget = nums[left] + nums[right];
                if (tempTarget > target - nums[threeBegin]) {
                    right--;
                } else if (tempTarget < target - nums[threeBegin]) {
                    left++;
                } else {
                    resultThreeSum.emplace_back(std::vector<int>{nums[threeBegin], nums[left], nums[right]});
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