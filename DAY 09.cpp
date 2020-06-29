// Is Subsequence

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(!s.length())
            return true;
        if(!t.length())
            return false;
        
        if(s[0] == t[0])
            return isSubsequence(s.substr(1), t.substr(1));
        else
            return isSubsequence(s, t.substr(1));
    }
};
