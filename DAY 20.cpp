// Permutation Sequence

#define ll int
class Solution {
public:
    string helper(int n, int k, map<int, bool>& mp, ll* dp) {
        if(k == 0) {
            return "";
        }
        
        ll curr = (n / dp[k-1]);
        if((n % dp[k - 1]) == 0)
            curr--;
        auto it = mp.begin();
        while((curr--)>0)
            ++it;
            
        string ans = to_string((it) -> first);
        mp.erase(it);
        int nextn = n % dp[k - 1];
        if(nextn == 0)
            nextn = dp[k - 1];
        string smallAns = helper(nextn, k - 1, mp, dp);
        return ans + smallAns;
    }
    
    string getPermutation(int n, int k) {
        map<int, bool> mp;
        for(int i = 1; i <= n; i++)
            mp[i] = true;
        ll dp[n];
        dp[0] = 1;
        for(int i = 1; i < n; i++)
            dp[i] = i*dp[i - 1];
    
        return helper(k, n, mp, dp);
    }
};