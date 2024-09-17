class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        if(intervals.empty()) return {};

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;

        vector<int> current_interval = intervals[0];

        for(int i = 1; i < intervals.size(); i++)
        {
            if(current_interval[1] >= intervals[i][0])
            {
                current_interval[1] = max(current_interval[1], intervals[i][1]);
            }

            else
            {
                merged.push_back(current_interval);
                current_interval = intervals[i];
            }
        }   

        merged.push_back(current_interval);

        return merged;
    }
};