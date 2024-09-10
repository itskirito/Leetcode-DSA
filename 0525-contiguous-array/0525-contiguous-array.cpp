// class Solution {
// public:
//     int findMaxLength(vector<int>& nums) 
//     {
//         int n = nums.size();
//         vector<int> prefixSum(n, 0);  // Initialize prefixSum vector with size n
//         prefixSum[0] = nums[0];  // Initialize the first element of prefixSum

//         // Convert 0s to -1s in the original nums array
//         for(int i = 0; i < n; i++)
//         {
//             if(nums[i] == 0)
//             {
//                 nums[i] = -1;
//             }
//         }

//         // Calculate the prefix sum array
//         for(int i = 1; i < n; i++)  // Start from i = 1 to avoid accessing prefixSum[-1]
//         {
//             prefixSum[i] = prefixSum[i - 1] + nums[i];
//         }

//         unordered_map<int, int> freqMap;  // To store the first occurrence of each prefix sum
//         int maxLength = 0;
//         int k = 0;  // We are looking for subarrays with sum equal to k (which is 0)
//         freqMap[0] = -1;  // This handles subarrays starting from index 0

//         // Iterate through the prefixSum array to find the maximum length subarray
//         for(int i = 0; i < n; i++)
//         {
//             // Check if (prefixSum[i] - k) exists in the map
//             if(freqMap.find(prefixSum[i] - k) != freqMap.end())
//             {
//                 int currentLength = i - freqMap[prefixSum[i] - k];
//                 maxLength = max(maxLength, currentLength);
//             }

//             // Store the first occurrence of each prefix sum
//             if(freqMap.find(prefixSum[i]) == freqMap.end())
//             {
//                 freqMap[prefixSum[i]] = i;
//             }
//         }

//         return maxLength;
//     }
// };


class Solution {
public:
    int findMaxLength(vector<int>& nums) 
    {
        int n = nums.size();
        
        // Replace 0 with -1 in the original nums array
        for(int i = 0; i < n; i++)
        {
            if(nums[i] == 0)
            {
                nums[i] = -1;
            }
        }

        unordered_map<int, int> freqMap;
        int runningSum = 0;
        int maxLength = 0;
        freqMap[0] = -1;  // This handles subarrays starting from index 0

        for(int i = 0; i < n; i++)
        {
            // Update the running sum
            runningSum += nums[i];
            
            // If (runningSum - k) exists, calculate the current length
            if(freqMap.find(runningSum) != freqMap.end())
            {
                int currentLength = i - freqMap[runningSum];
                maxLength = max(maxLength, currentLength);
            }
            else
            {
                // Store the first occurrence of the running sum
                freqMap[runningSum] = i;
            }
        }

        return maxLength;
    }
};


