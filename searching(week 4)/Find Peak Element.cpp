// Brute Force 
// T.C- O(N)
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if((i==0 || nums[i-1]<nums[i]) && (i==n-1 || nums[i]>nums[i+1])){
                return i;
            }
        }
        return -1;
    }
};
// Optimised Approach
// T.C- O(logn)
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        if(nums[0]>nums[1]) return 0;
        if(nums[n-1]>nums[n-2]) return n-1;

        int s=1;
        int e=n-2;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(nums[mid]>nums[mid-1] && nums[mid]> nums[mid+1]){
                return mid;
            }
            else if(nums[mid]<nums[mid+1]){
                s=mid+1;
            }
            else if(nums[mid]>nums[mid+1]){
                e=mid-1;
            }
        }
        return -1;
    }
};
