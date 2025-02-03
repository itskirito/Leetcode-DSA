class Solution {
public:
    string normalize(const string&word)
    {
        unordered_map<char, char> mapping;
        char ch = 'a';
        string normalized;

        for(char c : word)
        {
            if(mapping.find(c) == mapping.end())
            {
                mapping[c] = ch++;
            }

            normalized += mapping[c];
        }

        return normalized;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> result;
        string patternNorm = normalize(pattern);

        for(const string &word: words)
        {
            if(normalize(word) == patternNorm)
            {
                result.push_back(word);
            }
        }
        
        return result;
    }
};