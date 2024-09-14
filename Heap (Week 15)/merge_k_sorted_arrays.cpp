#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Info
{
public:
    int data;
    int rowIndex;
    int colIndex;
    Info(int val, int row, int col)
    {
        this->data = val;
        this->rowIndex = row;
        this->colIndex = col;
    }
};
class compare
{
public:
    bool operator()(Info *a, Info *b)
    {
        return a->data > b->data;
    }
};
void mergeKSortedArrays(int arr[][4], int n, int k, vector<int> &ans)
{
    priority_queue<Info *, vector<Info *>, compare> pq;
    // 1 step: process first k elements
    for (int row = 0; row < k; row++)
    {
        int element = arr[row][0];
        Info *temp = new Info(element, row, 0);
        pq.push(temp);
    }
    while (!pq.empty())
    {
        Info *temp = pq.top();
        pq.pop();
        int topData = temp->data;
        int topRow = temp->rowIndex;
        int topCol = temp->colIndex;
        // store in ans vector
        ans.push_back(topData);
        // next element for the same row, jisme se pop kiya hai abhi
        // use push bhi toh karna pdega ans vector me
        if (topCol + 1 < n)
        {
            // iska matlab row me or element bhi present hai
            Info* newinfo= new Info(arr[topRow][topCol+1],topRow,topCol+1);
            pq.push(newinfo);
        }
    }
}
int main()
{
    int arr[3][4] = {
        {1, 4, 8, 10},
        {2, 3, 6, 9},
        {5, 7, 11, 12}};
    int n = 4;   // number of column
    int k = 3; // number of rows
    vector<int> ans;
    mergeKSortedArrays(arr, n, k, ans);
    cout << "printing Ans array:" << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}