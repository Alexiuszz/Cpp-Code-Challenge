#include <iostream>

using namespace std;

int main()
{
    for (int i = 6; i < 9; ++i)
    {
        for (int j = 5; j < 9; ++j)
        {
            cout << i << " + " << j << " = " << i + j << "\n";
        }
    }
    return 0;
}