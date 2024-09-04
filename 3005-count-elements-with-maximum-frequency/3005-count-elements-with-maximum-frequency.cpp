class Solution {
public:
    int maxFrequencyElements(vector<int>& nums)    // takes a vector of integers nums as input
    {
     unordered_map<int, int>mp;      // initializes a unordered map mp, for storing frequency of elements
     for(auto &num : nums)
     {
         mp[num]++;
     }   

     int count = 0;
     int max_Freq = INT_MIN;     // initializes two variables count and maxfreq, count kjeeps track
     for(auto &m : mp)           // of total count of element with max freq and maxfreq holds the maximum frequency
     {                           // found so far, goes through the map and updates if it founds greater freq than current.
         if(m.second > max_Freq)
         {
             max_Freq = m.second;
         }
     }

     for(auto &m : mp)
     {                              
         if(m.second == max_Freq)   // iterates through the map again to count the no of elements that have
         {                          // maximum frequency, and increments the count by max_freq.
             count += max_Freq;
         }
     }
     return count;

    }
};