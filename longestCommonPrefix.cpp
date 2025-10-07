// 14. Longest Common Prefix
// Write a function to find the longest common prefix string amongst an array of strings.
// If there is no common prefix, return an empty string "".

// Example 1:
// Input: strs = ["flower","flow","flight"]
// Output: "fl"

// Example 2:
// Input: strs = ["dog","racecar","car"]
// Output: ""

#include <iostream>
#include <vector>
#include <string>

class Solution
{
public:
    std::string LongestCommonPrefix(std::vector<std::string> &strs)
    {
        if (strs.empty())
            return "";
        int end = int(strs[0].size());
        for (auto it = strs.begin() + 1; it != strs.end(); ++it)
        {
            if (end <= 0)
                return "";
            for (int j = 0; j < end; ++j)
            {
                if (strs[0][j] != (*it)[j])
                {
                    end = j;
                    break;
                }
            }
        }
        return strs[0].substr(0, end);
    };
};

int main()
{
    Solution s;
    std::vector<std::string> strs = {"flower", "flow", "flight"};

    std::cout << s.LongestCommonPrefix(strs);
}