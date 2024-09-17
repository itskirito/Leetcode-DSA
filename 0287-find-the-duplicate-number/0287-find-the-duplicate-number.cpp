class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        int n = nums.size() -1;
        vector<int> freq(n+1,0);

        for(int i = 0; i < nums.size(); i++)
        {
            if(freq[nums[i]] == 0)
            {
                freq[nums[i]]++;
            }
            else
            {
                return nums[i];
            }

        }
        // int slow = nums[0];
        // int fast = nums[0];

        // do
        // {
        //     slow = nums[slow];
        //     fast = nums[nums[fast]];
        // }    
        // while ( slow != fast);

        // slow = nums[0];

        // while(slow != fast)
        // {
        //     slow = nums[slow];
        //     fast = nums[fast];
        // }

        // return slow;
        return 0;
    }
};