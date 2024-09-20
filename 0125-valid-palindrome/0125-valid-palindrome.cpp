class Solution {
public:
    bool alphanumeric(char c)
    {
        if(c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z' )
        {
            return true;
        }

        return false;
    } 
    bool isPalindrome(string s) {

        int n = s.size();
        int l = 0;
        int r = n-1;

        while(l <= r)
        {
            while (l < r && !alphanumeric(s[l])) l++;
            while (r > l && !alphanumeric(s[r])) r--;

            if(tolower(s[l]) != tolower(s[r])) return false;

            l++;
            r--;
        }

        return true;
    }
};