#include<iostream>

using namespace std;

class Solution {
    public:
        int fib(int n) {
            if(n ==0)
                return 0;
            if ( n <= 2)
                return 1;
            
            return fib(n-1) + fib(n-2);
        }
};

int main() {
    Solution solution;
    cout << "Fib of 4 is 3 got: " << solution.fib(4) <<  endl;
    return 0;
}