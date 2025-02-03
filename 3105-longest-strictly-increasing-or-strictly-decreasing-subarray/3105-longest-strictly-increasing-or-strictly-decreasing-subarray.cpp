class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int incount = 1;
        int decount = 1;
        int maxlength = 1;

        for(int i = 1; i < n; i++)
        {
            // 1 4 3 3 2

            if(nums[i] > nums[i-1])
            {
                incount++; // 2 2
                decount = 1;
            }

            else if(nums[i] < nums[i-1])
            {
                decount++; // 2
                incount = 1;
            }

            else
            {
                decount = 1;
                incount = 1;
            }

            maxlength = max(maxlength, max(incount, decount)); // 2 2 2 2
        }

        return maxlength;
    }
};