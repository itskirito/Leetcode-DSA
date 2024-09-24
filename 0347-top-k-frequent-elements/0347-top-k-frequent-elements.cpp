class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int, int> mpp;
        for(int num: nums)
        {
            mpp[num]++;
        }

        int n = nums.size();
        vector<vector<int>> countArray(n+1);

        for(auto& index : mpp)
        {
            int num = index.first;
            int freq = index.second;

            countArray[freq].push_back(num);
        }

        vector<int> result;

        for(int i = n; i > 0 && result.size() < k; i--)
        {
            if(!countArray[i].empty())
            {
                for(int num : countArray[i])
                {
                    result.push_back(num);

                    if(result.size() == k)
                    {
                        break;
                    }
                }
            }
        }

        return result;
    }
};