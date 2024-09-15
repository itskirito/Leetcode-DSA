class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int n = nums.size();
        long long maximun_sum;
        long long variable_sum = 0;

        for(int i = 0; i< n; i++)
        {
            sum += nums[i];

            if(sums > maximum_sum)
            {
                maximun_sum = sum;
            }

            if(sum < 0)
            {
                sum = 0;
            }
        }

        return maximun_sum;    
    }
};