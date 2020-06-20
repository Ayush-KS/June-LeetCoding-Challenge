// Longest Duplicate Substring

#define ll long long int
#define mod 19260817
class Solution {
public:
    
    string ans = "";
    vector<ll> power;
    
    bool rabinKarp(int len, string const& t) {
        
        if(len == 0)
            return true;
        
        unordered_map<ll, vector<ll>> hash;
        ll current = 0;
        for (ll i = 0 ; i < len; i++) {
            current = ((current * 26) % mod + (t[i])) % mod;
        }
        hash[current].push_back(0);
        for(int j = len; j < t.size(); j++) {
            
            current = ((current - (long long) power[len - 1] * (t[j - len])) % mod + mod) % mod;
            current = (current * 26 + (t[j])) % mod;
            
            if(hash.find(current) == hash.end()) {
                hash[current].push_back(j - len + 1);
            } else {
                for(ll it : hash[current]) {
                    if(t.substr(it, len) == t.substr(j - len + 1, len)) {
                        ans = t.substr(it, len);
                        return true;
                    }
                }
                hash[current].push_back(j - len + 1);
            }
        }
        return false;
    }
    
    string longestDupSubstring(string s) {
        if(s.empty())
            return "";
        
        int lo = 1;
        int hi = s.size() - 1;
        power = vector<ll>(hi + 1, 1);
        for(int i = 1; i <= hi; i++) {
            power[i] = (power[i - 1]*26) % mod;
        }
        
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if(rabinKarp(mid, s)) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        
        
        return ans;
    }
};