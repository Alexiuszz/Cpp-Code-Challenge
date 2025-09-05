// Greates commion divisor of two numbers using Euclidean algorithm

#include <iostream>

using namespace std;

class GCD
{
    public:
        int gcd(int a, int b)
        {
            if (b == 0)
                return a;
            return gcd(b, a % b);
        };
        
        int gcd2(int m, int n)
        {
            if(n == 0)
                return m;
            int r = m % n;
            if(r == 0)
                return n;
            else
                return gcd2(n, r);
        }
};

int main()
{
    GCD newGCD;
    std::cout << "GCD of 48 and 18 is 6 got: " << newGCD.gcd(48, 18) << std::endl;
    std::cout << "GCD of 56 and 98 is 14 got: " << newGCD.gcd(56, 98) << std::endl;
    std::cout << "GCD of 101 and 10 is 1 got: " << newGCD.gcd(101, 10) << std::endl;
    std::cout << "GCD of 0 and 5 is 5 got: " << newGCD.gcd(0, 5) << std::endl;
}