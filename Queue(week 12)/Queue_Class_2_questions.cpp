#include <iostream>
#include <stack>
#include <queue>
using namespace std;
void reverseQueue(queue<int> &q)
{
    stack<int> s;

    // one by one queue se element stack me daalo
    while (!q.empty())
    {
        int frontelement = q.front();
        q.pop();
        s.push(frontelement);
    }

    // one by one stack se lo queue me push karo
    while (!s.empty())
    {
        int topelement = s.top();
        s.pop();
        q.push(topelement);
    }
}
void reverse(queue<int> &q)
{
    if (q.empty())
    {
        return;
    }
    int element = q.front();
    q.pop();

    reverse(q);

    q.push(element);
}
void reverseFirstK(queue<int> &q, int k)
{
    stack<int> s;
    // push first k elements into stack
    int n = q.size();
    if (k > n || k == 0)
    {
        return;
    }
    for (int i = 0; i < k; i++)
    {
        int temp = q.front();
        q.pop();
        s.push(temp);
    }

    // push k element into queue
    while (!s.empty())
    {
        int temp = s.top();
        s.pop();
        q.push(temp);
    }
    // pop and push first (n-k) elements into queue again
    for (int i = 0; i < (n - k); i++)
    {
        int temp = q.front();
        q.pop();
        q.push(temp);
    }
}
void interleaveQueue(queue<int> &first)
{
    queue<int> second;
    // push first half of first queue in second queue
    int size = first.size();
    for (int i = 0; i < size / 2; i++)
    {
        int temp = first.front();
        first.pop();
        second.push(temp);
    }
    // merge both the halves
    // into the original queue - named as first
    for (int i = 0; i < size / 2; i++)
    {
        int temp = second.front();
        second.pop();
        first.push(temp);
        temp = first.front();
        first.pop();
        first.push(temp);
    }
}

void printFirstNegative(int *arr, int n, int k)
{
    deque<int> dq;

    // process first k elements - first window
    for (int index = 0; index < k; index++)
    {
        int element = arr[index];
        if (element < 0)
        {
            dq.push_back(index);
        }
    }
    // process remaining windows-> removal and addition
    for (int index = k; index < n; index++)
    {
        // aage badhne se pehle purani window ka answer niklao
        if (dq.empty())
        {
            cout << "0 " << endl;
        }
        else
        {
            cout << arr[dq.front()] << " ";
        } // Removal - jo bhi index out of range hai, usko queue me se remove krdo
        // ye niche vala part hi bhulte hai
        if (index - dq.front() >= k)
        {
            dq.pop_front();
        }

        // Addition
        if (arr[index] < 0)
        {
            dq.push_back(index);
        }
    }
    // last window ka answer print kardo
    if (dq.empty())
    {
        cout << "0 " << endl;
    }
    else
    {
        cout << arr[dq.front()] << " ";
    }
}
int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    // q.push(60);
    int arr[]={2,-5,4,-1,-2,8,5};
    int size=7;
    int k=3;
    printFirstNegative(arr,size,k);
    // reverse(q);
    // reverseFirstK(q,4);
    // interleaveQueue(q);
    // cout << "Printing Queue" << endl;
    // while (!q.empty())
    // {
    //     int element = q.front();
    //     q.pop();
    //     cout << element << " ";
    // }
    return 0;
}