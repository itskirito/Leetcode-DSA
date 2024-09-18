class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        int n = nums.size();

        int count1 = 0, count2 = 0;
        int cand1 = INT_MIN;
        int cand2 = INT_MIN;

        for(int i = 0; i < n; i++)
        {
            if(count1 == 0 && nums[i] != cand1)
            {
                count1++;
                cand1 = nums[i];
            }

            else if(count2 == 0 && nums[i] != cand2)
            {
                count2++;
                cand2 = nums[i];
            }

            else if(cand1 == nums[i]) count1++;
            else if(cand2 == nums[i]) count2++;

            else
            {
                count1--;
                count2--;
            }
        } 

        vector<int> result;

        int cnt1 = 0, cnt2 = 0;

        for(int i =0; i < n; i++)
        {
            if(nums[i] == cand1) cnt1++;
            else if(nums[i] == cand2) cnt2++;
        }

        int thresold = n/3;
        
        if(cnt1 > thresold) result.push_back(cand1);
        if(cnt2 > thresold) result.push_back(cand2);

        return result;  
    }
};