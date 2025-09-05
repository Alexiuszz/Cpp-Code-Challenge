#include <iostream>

class Solution
{
public:
        int mySqrt(int x)
        {
                if (x < 2)
                        return x;
                int l, m, r, result;
                l = 1;
                r = x / 2;
                result = 0;
                while (l <= r)
                {
                        m = l + (r - l) / 2;
                        if (m <= x / m)
                        {
                                result = m;
                                l = m + 1;
                        }
                        else
                                r = m - 1;
                }
                return result;
        }

        int mySqrt2(int x)
        {
                if (x < 2)
                        return x;
                int l, m, r;
                l = 1;
                r = x / 2;
                m = 1;
                while (m != x / m)
                {
                        m = l + (r - l) / 2;
                        if (m < x / m && (m + 1) > x / (m + 1))
                                return m;
                        else if (m > x / m)
                                r = m - 1;
                        else if ((m + 1) <= x / (m + 1))
                                l = m + 1;
                }
                return m;
        };
};

int main()
{
        Solution newSqr;
        std::cout << "Square Root of 4 should be 2 got: " << newSqr.mySqrt2(4) << std::endl;
        std::cout << "Square Root of 7 should be 2 got: " << newSqr.mySqrt2(7) << std::endl;
        std::cout << "Square Root of 9 should be 3 got: " << newSqr.mySqrt2(9) << std::endl;
        std::cout << "Square Root of 0 should be 0 got: " << newSqr.mySqrt2(0) << std::endl;
}