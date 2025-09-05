#include <iostream>
#include <vector>

using namespace std;
class InsertionSort
{
    public:
        void insertionSort(vector<int> &arr)
        {
            int n = arr.size();
            for (int i = 1; i < n; i++)
            {
                int key = arr[i];
                int j = i - 1;

                // Move elements of arr[0..i-1], that are greater than key,
                // to one position ahead of their current position
                while (j >= 0 && arr[j] > key)
                {
                    arr[j + 1] = arr[j];
                    j = j - 1;
                }
                arr[j + 1] = key;
            }
        }
};

int main()
{
    InsertionSort sorter;
    vector<int> arr = {4, 3, 2, 1, 6};
    sorter.insertionSort(arr);
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}