class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        if(nums.empty()) return 0;

        int n = nums.size();
        sort(nums.begin(), nums.end());

        int max_length = 1;
        int count = 1;

        for(int i = 1; i < n; i++)
        {
            if(nums[i] == nums[i-1] + 1)
            {
                count++;
            }
            else if(nums[i] == nums[i-1])
            {
                count = count;
            }
            else
            {
                count = 1;
            }

            max_length = max(count, max_length);
        } 

        return max_length;   
    }
};