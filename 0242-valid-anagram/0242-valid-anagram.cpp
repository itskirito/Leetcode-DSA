class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        int n = s.size();
        int m = t.size();

        if(n != m) return false;

        int charCount[26] = {0};
        for(auto c : s){
            charCount[c - 'a']++;
        }    

        for(auto c : t)
        {
            charCount[c - 'a']--;
            if(charCount[c-'a'] < 0)
            {
                return false;
            }
        }

        return true;
    }
};