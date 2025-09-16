#include <vector>
#include <limits>
using namespace std;


//without sentinel
class Solution {
public:
    void mergeSort(vector<int>& a) {
        if (a.size() < 2) return;
        vector<int> buf(a.size());
        mergeSort(a, buf, 0, static_cast<int>(a.size())); // [l, r)
    }

private:
    // sort a[l:r)
    static void mergeSort(vector<int>& a, vector<int>& buf, int l, int r) {
        if (r - l <= 1) return;
        int m = l + (r - l) / 2;
        mergeSort(a, buf, l, m);
        mergeSort(a, buf, m, r);
        // merge [l:m) and [m:r) into buf, then copy back
        int i = l, j = m, k = l;
        while (i < m && j < r) {
            if (a[i] <= a[j]) buf[k++] = a[i++];
            else               buf[k++] = a[j++];
        }
        while (i < m) buf[k++] = a[i++];
        while (j < r) buf[k++] = a[j++];
        for (int t = l; t < r; ++t) a[t] = buf[t];
    }
};


//with sentinel
class Solution {
public:
    void mergeSort(vector<int>& arr) {
        if (arr.size() < 2) return;
        mergeSort(arr, 0, static_cast<int>(arr.size()) - 1);
    }

    void mergeSort(vector<int>& arr, int l, int r) {
        if (l >= r) return;
        int mid = l + (r - l) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }

private:
    static void merge(vector<int>& arr, int l, int mid, int r) {
        int nl = mid - l + 1;
        int nr = r - mid;

        // allocate space for halves plus sentinels
        vector<int> left(nl + 1), right(nr + 1);

        // copy halves
        for (int i = 0; i < nl; ++i) left[i] = arr[l + i];
        for (int j = 0; j < nr; ++j) right[j] = arr[mid + 1 + j];

        // sentinels
        const int INF = numeric_limits<int>::max();
        left[nl]  = INF;
        right[nr] = INF;

        // merge
        int i = 0, j = 0;
        for (int k = l; k <= r; ++k) {
            if (left[i] <= right[j]) {
                arr[k] = left[i++];
            } else {
                arr[k] = right[j++];
            }
        }
    }
};
