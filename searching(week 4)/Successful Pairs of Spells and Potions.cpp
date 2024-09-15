// 2300. Successful Pairs of Spells and Potions
// Brute force solution
// TC:O(n*m)
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        // Vector to store the result for each spell
        vector<int> pairs;
        // Sizes of spells and potions
        int n = spells.size();
        int m = potions.size();
        // Iterate through each spell
        for (long long i = 0; i < n; i++) {
            long long cnt = 0; // Counter for successful pairs
            // Iterate through each potion
            for (long long j = 0; j < m; j++) {
                // Calculate the product of the current spell and potion
                long long product = static_cast<long long>(spells[i]) * potions[j];
                // Check if the product meets or exceeds the success threshold
                if (product >= success) {
                    cnt++;
                }
                // Note: No need to reset product here as it is reassigned in the next iteration
            }
            // Store the count of successful pairs for the current spell
            pairs.push_back(cnt);
        }
        return pairs;
    }
};
//Optimised soltuion 
// Time Complexity :
//     Sorting the potions takes 𝑂(𝑚logm) where m is the size of the potions arrFor each spell,
//     binary search takes O(logm), and there are n spells.
//     Overall time complexity is O(mlogm + nlogm) 

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        // Sort the potions array to use binary search
        sort(potions.begin(), potions.end());
        
        vector<int> result;
        int m = potions.size();
        
        // Function to perform binary search
        auto binarySearch = [&](int spell, long long required) {
            int left = 0, right = m - 1;
            int pos = m;  // Default to 'm' meaning no valid potion found
            
            while (left <= right) {
                int mid = left + (right - left) / 2;
                
                // If the potion at mid is valid, search to the left (smaller values)
                if (potions[mid] >= required) {
                    pos = mid;  // Found a valid potion
                    right = mid - 1;  // Continue searching left
                } else {
                    left = mid + 1;  // Move to the right part of the array
                }
            }
            return pos;
        };
        
        // Iterate over each spell
        for (int spell : spells) {
            // Calculate the required minimum potion value to meet the success condition
            long long required = (success + spell - 1) / spell;  // Ceil(success / spell)
            
            // Use binary search to find the first valid potion
            int pos = binarySearch(spell, required);
            
            // Count how many potions can make a successful pair with the current spell
            int count = m - pos;  // Number of potions >= required
            
            // Store the count for the current spell
            result.push_back(count);
        }
        
        return result;
    }
};
