// class Solution {
// public:
//     vector<int> searchRange(vector<int>& nums, int target) 
//     {
//         int ind1 = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
//         if(ind1 != nums.end() && nums[ind1] == target) return ind1;

//         int ind2 = -1;
//         ind2 = upper_bound(nums.begin(), nums.end(), target) - nums.begin());
//         if(ind2 >= 0 && nums[ind2] == target) return ind2;    
//     }
// };

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        int ind1 = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        // Check if target is not found
        if (ind1 == nums.size() || nums[ind1] != target) return {-1, -1}; 

        // Find the upper bound and adjust ind2 to get the last occurrence
        int ind2 = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
        
        return {ind1, ind2}; // Return the starting and ending indices
    }
};
