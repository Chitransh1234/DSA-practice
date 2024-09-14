#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

void generateSubsequences(vector<int> &A, int K, int index, vector<int> &curr, vector<vector<int>> &vec)
{
    if (curr.size() == 2 * K)
    {
        vec.push_back(curr);
        return;
    }
    if (index >= A.size())
    {
        return;
    }
    curr.push_back(A[index]);
    generateSubsequences(A, K, index + 1, curr, vec);
    curr.pop_back();
    generateSubsequences(A, K, index + 1, curr, vec);
}

int calculateF(vector<int> &B, int K)
{
    int or1 = 0, or2 = 0;
    for (int i = 0; i < K; ++i)
    {
        or1 |= B[i];
    }
    for (int i = K; i < 2 * K; ++i)
    {
        or2 |= B[i];
    }
    return or1 ^ or2;
}

int solve(int N, int K, vector<int> &A)
{
    vector<vector<int>> vec;
    vector<int> curr;
    generateSubsequences(A, K, 0, curr, vec);

    int result = INT_MIN;
    for (auto B : vec)
    {
        result = max(result, calculateF(B, K));
    }
    return result;
}

int main()
{
    int N = 3;
    int K = 1;
    vector<int> A = {2, 4, 5};

    int result = solve(N, K, A);
    cout << "Maximum value of F(B): " << result << endl;

    return 0;
}
