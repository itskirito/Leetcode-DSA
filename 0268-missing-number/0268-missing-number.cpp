class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        long long n, S, Sn;
        n = nums.size();

        Sn = (n*(n+1))/2;

        S = 0;
        for(int i = 0; i < n; i++)
        {
            S += nums[i];
        }    

        int X = Sn - S;
        return (int)X;
    }
};