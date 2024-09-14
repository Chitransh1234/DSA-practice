#include <iostream>
#include <queue>
using namespace std;
int getKthSmallestElement(int arr[], int n, int k)
{
    priority_queue<int> pq;
    // first k elements process kro
    for (int i = 0; i < k; i++)
    {
        int element = arr[i];
        pq.push(element);
    }
    // remaining element ko tabhi insert karenge jab vo root se chotte honge
    for (int i = k; i < n; i++)
    {
        int element = arr[i];
        if (element < pq.top())
        {
            pq.pop();
            pq.push(element);
        }
    }
    int ans = pq.top();
    return ans;
}
int getKthGreatestelement(int arr[], int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    // first k elements process kro
    for (int i = 0; i < k; i++)
    {
        int element = arr[i];
        pq.push(element);
    }
    // remaining element ko tabhi insert karenge jab vo root se chotte honge
    for (int i = k; i < n; i++)
    {
        int element = arr[i];
        if (element > pq.top())
        {
            pq.pop();
            pq.push(element);
        }
    }
    int ans = pq.top();
    return ans;
}
int main()
{
    int arr[] = {3, 5, 4, 6, 9, 8, 7};
    int n = 7;
    int k = 3;
    cout << getKthSmallestElement(arr, n, k)<<endl;
    cout<<getKthGreatestelement(arr,n,k);
    // code for min heap
    // min heap creation
    // priority_queue<int,vector<int>,greater<int>> pq;
    // //insertion
    // pq.push(100);
    // pq.push(90);
    // pq.push(70);
    // cout<<"Top element of Heap:"<<pq.top()<<endl;
    // pq.pop();
    // cout << "Top element of Heap:" << pq.top() << endl;
    // cout << "Size of max Heap:" << pq.size() << endl;
    // if(pq.empty()){
    //     cout<<"Empty"<<endl;
    // }
    // else{
    //     cout<<"Not Empty"<<endl;
    // }
    // the below code is for max heap
    // priority_queue<int> pq;
    // // insertion
    // pq.push(10);
    // pq.push(20);
    // pq.push(30);
    // pq.push(40);
    // cout << "Top element of Heap:" << pq.top() << endl;
    // pq.pop();
    // cout << "Top element of Heap:" << pq.top() << endl;
    // cout << "Size of max Heap:" << pq.size() << endl;
    // if(pq.empty()){
    //     cout<<"Empty"<<endl;
    // }
    // else{
    //     cout<<"Not Empty"<<endl;
    // }
}