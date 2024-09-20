class Solution {
public:
    bool isPal(string&str, int l, int r)
    {
        if(l >= r)
        {
            return true;
        }

        if(str[l] == str[r])
        {
            return isPal(str, l+1, r-1);
        }

        return false;
    } 
    bool isPalindrome(string s) {
        string newStr;

        for(auto c : s)
        {
            if(isalnum(c))
                newStr += tolower(c);
        }

        int n = newStr.size();
        int l = 0;
        int r = n-1;

        return isPal(newStr, l, r);
    }
};