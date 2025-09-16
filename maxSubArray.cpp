#include <iostream>
#include <vector>
#include <limits>
#include <tuple>

using namespace std;

class Solution {
public:
    // Returns the maximum subarray sum. If you want indices, expose the tuple.
    long long maxSubArray(const vector<int>& a) {
        if (a.empty()) return 0;            // define empty case as 0, or throw
        int L,R; long long S;
        tie(L, R, S) = maxSubArray(a, 0, static_cast<int>(a.size())); // [0, n)
        return S;
    }

    long long kadaneMaxSubArray(const vector<int>& a) {
    if (a.empty()) return 0;  // special case: no elements

    long long best = a[0], cur = a[0]; // initialize with first element

    for (size_t i = 1; i < a.size(); ++i) {
        cur = max<long long>(a[i], cur + a[i]);
        best = max(best, cur);
    }

    return best;
}


private:
    // returns {lo, hi, sum} for the best subarray within [l, r)
    static tuple<int,int,long long> maxSubArray(const vector<int>& a, int l, int r) {
        if (r - l == 1) {                    // single element
            return {l, l, static_cast<long long>(a[l])};
        }
        int m = l + (r - l) / 2;             // split [l, m) and [m, r)
        int lLo, lHi; long long lSum;
        int rLo, rHi; long long rSum;
        int cLo, cHi; long long cSum;
        tie(lLo, lHi, lSum) = maxSubArray(a, l, m);
        tie(rLo, rHi, rSum) = maxSubArray(a, m, r);
        tie(cLo, cHi, cSum) = maxCross(a, l, m, r);

        if (lSum >= rSum && lSum >= cSum) return {lLo, lHi, lSum};
        if (rSum >= lSum && rSum >= cSum) return {rLo, rHi, rSum};
        return {cLo, cHi, cSum};
    }

    // Best subarray that crosses the midpoint: ends in [l, m) and starts in [m, r)
    static tuple<int,int,long long> maxCross(const vector<int>& a, int l, int m, int r) {
        long long bestLeft = numeric_limits<long long>::lowest();
        long long sum = 0;
        int maxLeft = m - 1;
        for (int i = m - 1; i >= l; --i) {
            sum += a[i];
            if (sum > bestLeft) {
                bestLeft = sum;
                maxLeft = i;
            }
        }

        long long bestRight = numeric_limits<long long>::lowest();
        sum = 0;
        int maxRight = m;
        for (int i = m; i < r; ++i) {
            sum += a[i];
            if (sum > bestRight) {
                bestRight = sum;
                maxRight = i;
            }
        }

        return {maxLeft, maxRight, bestLeft + bestRight};
    }
};

int main()
{
    Solution solution;
    vector<int> arr = {3,-2,5,7,-5,-1,5,2};
    cout<< "Max Sub " << solution.maxSubArray(arr) << endl;
} 