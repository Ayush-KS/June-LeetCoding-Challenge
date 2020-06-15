// Cheapest Flights Within K Stops

class Solution {
public:
    
    int dfs(vector<vector<pair<int, int>>>& graph, int si, int ei, int k, vector<vector<int>>& dp) {
        if(si == ei)
            return 0;
        
        if(k < 0)
            return -1;
        
        if(dp[si][k] != -1) {
            return dp[si][k];
        }
        
        int ans = -1;
        for(pair<int,int> p : graph[si]) {
            int smallAns = dfs(graph, p.first, ei, k - 1, dp);
            if(smallAns != -1) {
                if(ans != -1)
                    ans = min(ans, p.second + smallAns);
                else
                    ans = p.second + smallAns;
            }
        }
        dp[si][k] = ans;
        return ans;
    }
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<pair<int, int>>> graph(n, vector<pair<int, int>>());
        vector<vector<int>> dp(n, vector<int>(K + 1, -1));
        for(vector<int> v : flights) {
            graph[v[0]].push_back({v[1], v[2]});
        }
           
        return dfs(graph, src, dst, K, dp);
    }
};