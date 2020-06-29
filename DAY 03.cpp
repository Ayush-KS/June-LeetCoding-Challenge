// Two City Scheduling

class Solution {
public:
    
    map<pair<int, pair<int, int>>, int> mp;
    
    int helper(int i, vector<vector<int>>& costs, int a, int b) {
        if(i == costs.size())
            return 0;
        if(mp.find({i, {a, b}}) != mp.end())
            return mp[{i, {a, b}}];
        
        int n = costs.size() / 2;
        
        if(a == n) {
            return costs[i][1] + helper(i + 1, costs, a, b + 1);
        }
        if(b == n) {
            return costs[i][0] + helper(i + 1, costs, a + 1, b);
        }
        
        mp[{i, {a, b}}] = min(costs[i][1] + helper(i + 1, costs, a, b + 1), costs[i][0] + helper(i + 1, costs, a + 1, b));
        return  mp[{i, {a, b}}];
    }
    
    int twoCitySchedCost(vector<vector<int>>& costs) {
        return helper(0, costs, 0, 0);
    }
};
