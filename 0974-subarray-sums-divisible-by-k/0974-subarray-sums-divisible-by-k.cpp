class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) 
    {
        int n = nums.size();
        vector<int> prefixSum(n, 0);
        prefixSum[0] = nums[0] % k;
        if (prefixSum[0] < 0) 
        prefixSum[0] += k; 

        for(int i = 1; i < n; i++)
        {
            prefixSum[i] = (prefixSum[i-1] + nums[i]) % k;
            if (prefixSum[i] < 0) 
                prefixSum[i] += k; 
        }

        unordered_map<int, int> freqMap;
        for(int value : prefixSum)
        {
            freqMap[value]++;
        }

        freqMap[0]++;
        int totalSubarrays = 0;

        for(auto& count : freqMap )
        {
            int freq = count.second;

            if(freq > 1)
            {
                totalSubarrays += (freq*(freq-1))/2;
            }
        }

        return totalSubarrays;

        
    }
};