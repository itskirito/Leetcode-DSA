class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int n = nums.size();

        int prefix[n];

        prefix[0] = 1;
        for(int i = 1; i < n; i++)
        {
            prefix[i] = prefix[i-1]*nums[i-1];
        }

        int suffix[n];

        suffix[n-1] = 1;
        for(int i = n-1; i >= 0; i--)
        {
            suffix[i] = suffix[i+1]*nums[i+1];
        }

        vector<int> product;
        for(int i = 0; i< n; i++)
        {
            product[i] = prefix[i]*suffix[i];
        }

        return product;
    }
};