#include <iostream>
#include <vector>

// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.

// Example 1:
// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

// Example 2:
// Input: nums = [3,2,4], target = 6
// Output: [1,2]

// Example 3:
// Input: nums = [3,3], target = 6
// Output: [0,1]

class Solution
{
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> seen;

        for (int i; i < nums.size(); i++) {
            int compliment = target - nums[i];

            if (seen.find(compliment) == seen.end()) {
                seen.insert({nums[i], i});
            } else {
                return std::vector<int> { seen[compliment], i };
            }
        }

        return std::vector<int> {};
    }
    std::vector<int> twoSumN(std::vector<int> &nums, int target)
    {
        for (int i = 0; i < (int)nums.size() - 1; i++)
        {
            for (int j = i + 1; j < (int)nums.size(); j++)
            {
                int sum = nums[i] + nums[j];
                if (sum == target)
                    return {i, j};
            }
        }
        return {0, 0};
    }
};

int main()
{
    Solution s;
    std::vector<int> nums = {2, 7, 11, 15};
    std::vector<int> res = s.twoSum(nums, 18);
    std::cout << "[" << res[0] << ", " << res[1] << "]";
}