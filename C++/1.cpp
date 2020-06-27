// 两数之和

#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> resultMap;
        std::vector<int> resultVector;
        auto nums_size = nums.size();
        for (int pos = 0; pos != nums_size; ++pos) {
            if (resultMap.find(nums[pos]) != resultMap.end()) {
                resultVector.push_back(resultMap.at(nums[pos]));
                resultVector.push_back(pos);
                break;
            } else {
                resultMap[target - nums[pos]] = pos;
            }
        }
        return resultVector;
    }
};
