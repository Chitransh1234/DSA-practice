#include <iostream>
#include <deque>
#include <vector>
using namespace std;
int maxminSlidingWindow(vector<int> &nums, int k)
{
    int ans=0;
    deque<int> dq,dq2;
    // first window ko process karo
    for (int i = 0; i < k; i++)
    {
        int element = nums[i];
        // jitne bhi queue ke aandr chotte elements hai remove kardo
        while (!dq.empty() && element > nums[dq.back()])
        {
            dq.pop_back();
        }
        // now insert kardo
        dq.push_back(i);

        // min. element store karaenge
        while (!dq2.empty() && element <= nums[dq2.back()])
        {
            dq2.pop_back();
        }
        // now insert kardo
        dq2.push_back(i);
    }
    ans+= nums[dq.front()]+nums[dq2.front()];
    // remaining window ko process karo
    // removal
    // addition

    for (int i = k; i < nums.size(); i++)
    {


        // removal
        // out of range elements
        if (!dq.empty() && i - dq.front() >= k)
        {
            dq.pop_front();
        }
        // chotte elements pop kardo
        int element = nums[i];
        while (!dq.empty() && element > nums[dq.back()])
        {
            dq.pop_back();
        }
        // addition
        dq.push_back(i);
        //min. element ka removal and addition in dq2
        if (!dq2.empty() && i - dq2.front() >= k)
        {
            dq2.pop_front();
        }
        // chotte elements pop kardo
        
        while (!dq2.empty() && element < nums[dq2.back()])
        {
            dq2.pop_back();
        }
        // addition
        dq2.push_back(i);

        ans+= nums[dq.front()]+nums[dq2.front()];
    }
    // last window ka answer store karlo
    // ans+= nums[dq.front()]+nums[dq2.front()];
    return ans;
}
int main()
{
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(5);
    nums.push_back(-1);
    nums.push_back(7);
    nums.push_back(-3);
    nums.push_back(-1);
    nums.push_back(-2);
    int k=4;
    cout<<"Total sum is :"<<maxminSlidingWindow(nums,k);
    return 0;
}