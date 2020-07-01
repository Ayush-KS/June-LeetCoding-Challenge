// Dungeon Game

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<int> dp(n);
        
        dp[n - 1] = grid[m - 1][n - 1] > 0 ? 1 : abs(grid[m - 1][n - 1]) + 1;
        
        for(int i = m - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                if((i == m - 1) && (j == n - 1))
                    continue;
                int first, second;
                first = second = INT_MAX;
                if(j < n - 1) {
                    first = grid[i][j] - dp[j + 1] >= 0 ? 1 : abs(grid[i][j] - dp[j + 1]);
                }
                if(i < m - 1) {
                    second = grid[i][j] - dp[j] >= 0 ? 1 : abs(grid[i][j] - dp[j]);
                }
                dp[j] = min(first, second);
            }
        }
        
        return dp[0];
    }
};
