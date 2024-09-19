class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        if(nums.empty()) return 0;

        int n = nums.size();
        int max_length = 1;
        
        unordered_set<int> st;
        for(int i = 0; i < n; i++)
        {
            st.insert(nums[i]);
        }

        for(auto it : st)
        {
            if(st.find(it - 1) == st.end())
            {
                int count = 1;
                int x  = it;
                while(st.find(x+1) != st.end())
                {
                    x = x +1;
                    count = count +1;
                }

                max_length = max(max_length, count);
            }
        }

        return max_length;   
    }
};