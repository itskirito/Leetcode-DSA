class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        unordered_map<string, vector<string>> res;

        for(string& s : strs)
        {
        int charCount[26] = {0};

        for(char c : s)
        {
            charCount[c-'a']++;
        }

        string key = "";
        for(int i = 0; i < 26; i++)
        {
            key += string(charCount[i], 'a' + i);
        }

        res[key].push_back(s);
        } 

        vector<vector<string>> result;
        for(auto& group : res)
        {
            result.push_back(group.second);
        } 

        return result;
    }
};