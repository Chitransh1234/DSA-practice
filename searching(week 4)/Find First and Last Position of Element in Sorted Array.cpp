// Time Complexity-> O(N)
// Using Linear searching
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans(2,-1); 
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                if(ans[0]==-1){
                    ans[0]=i;
                }
                ans[1]=i;
            }
        }
        return ans;
    }
};

// --------------------> Using Binary Search <--------------------------------------------
Time Complexity -> O(log(n))
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();  // Size of the input array
        int s = 0;            // Start index for binary search
        int e = n - 1;        // End index for binary search
        vector<int> ans(2, -1); // Initialize result with [-1, -1] for no target found

        // Binary search for the first occurrence of target
        while (s <= e) {
            int mid = s + (e - s) / 2; // Calculate the middle index
            if (nums[mid] == target) {
                ans[0] = mid; // Store the first occurrence index
                e = mid - 1;  // Continue searching on the left side
            }
            else if (nums[mid] < target) {
                s = mid + 1;  // Move to the right half
            }
            else {
                e = mid - 1;  // Move to the left half
            }
        }

        // Reset the start and end indices for searching the last occurrence
        s = 0;
        e = n - 1;

        // Binary search for the last occurrence of target
        while (s <= e) {
            int mid = s + (e - s) / 2; // Calculate the middle index
            if (nums[mid] == target) {
                ans[1] = mid; // Store the last occurrence index
                s = mid + 1;  // Continue searching on the right side
            }
            else if (nums[mid] < target) {
                s = mid + 1;  // Move to the right half
            }
            else {
                e = mid - 1;  // Move to the left half
            }
        }

        return ans; // Return the result vector with first and last occurrence
    }
};
