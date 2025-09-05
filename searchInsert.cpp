#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
  int searchInsert(std::vector<int> nums, int target)
  {
    int head = 0, mid, tail = nums.size() - 1;
    while (tail >= head)
    {
      mid = (head + tail) >> 1;
      if (nums[mid] == target)
        return mid;
      if (nums[mid] > target)
      {
        tail = mid - 1;
      }
      else
      {
        head = mid + 1;
      }
    }
    if (nums[mid] > target)
    {
      return mid - 1 < 0 ? 0 : nums[mid - 1] == target ? mid - 1
                                                       : mid;
    }
    else
      return mid + 1;
  }
};

int main()
{
  vector<int> nums = {1, 2, 3, 4, 6};
  int target = 5;
  Solution sol = Solution();
  cout << sol.searchInsert(nums, target);
}