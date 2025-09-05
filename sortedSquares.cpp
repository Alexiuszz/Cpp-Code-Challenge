#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
        vector<int> sortedSquares(vector<int> &nums)
        {
                const int size = nums.size();
                int i = 0, j = size - 1;
                vector<int> arr(size);

                for (int x = size - 1; x >= 0; x--)
                {
                        int sqr1 = nums[i] * nums[i];
                        int sqr2 = nums[j] * nums[j];
                        if (sqr1 >= sqr2)
                        {
                                arr[x] = sqr1;
                                i++;
                        }
                        else
                        {
                                arr[x] = sqr2;
                                j--;
                        }
                }
                return arr;
        }
};
        int main()
        {
                 Solution sort;
                vector<int> arr = {4, 3, 2, 1, 6};
                int n = arr.size();
                vector<int> newArr= sort.sortedSquares(arr);

                for (int i = 0; i < n; i++)
                {
                        cout << newArr[i] << " ";
                }
                return 0;
        }
