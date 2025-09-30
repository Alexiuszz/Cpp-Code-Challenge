#include <iostream>
#include <vector>

using namespace std;
using matrix = vector<vector<int>>;

class Solution
{
public:
    matrix matrixMult(matrix &A, matrix &B)
    {
        int n = A.size();
        matrix C(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        return C;
    }

    matrix add(matrix &A, matrix &B)
    {
        int n = A.size();
        matrix C(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                C[i][j] = A[i][j] + B[i][j];
            }
        }
        return C;
    }



    void printMatrix(const matrix &M)
    {
        for (auto &row : M)
        {
            for (int val : row)
                cout << val << " ";
            cout << "\n";
        }
    }
};

int main()
{
    matrix A = {
        {1, 2, 3},
        {4, 5, 6},
        {5, 8, 9}};
    matrix B = {
        {9, 8, 7},
        {6, 7, 4},
        {3, 2, 1}};
    Solution solution;
    matrix C = solution.add(A, B);
    solution.printMatrix(C);
    return 0;
}