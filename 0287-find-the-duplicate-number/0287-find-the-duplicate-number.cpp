class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        int tortoise = nums[0];
        int hare = nums[0];

        do{
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
        }while(tortoise != hare);

        tortoise = nums[0];
        while(tortoise != hare)
        {
            tortoise = nums[tortoise];
            hare = nums[hare];
        }

        return hare;


        // int n = nums.size() -1;
        // vector<int> freq(n+1,0);

        // for(int i = 0; i < nums.size(); i++)
        // {
        //     if(freq[nums[i]] == 0)
        //     {
        //         freq[nums[i]]++;
        //     }
        //     else
        //     {
        //         return nums[i];
        //     }

        // }
        
    }
};