// Largest Divisible Subset

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if(!n)
            return {};
        unordered_map<int, int>gi indices;
        for(int i = 0; i < n; i++) {
            indices[nums[i]] = i;
        }
        vector<int> temp = nums;
        sort(nums.begin(), nums.end());
        vector<int> dp (n, 1);
        
        
        for(int i = 0; i < n; i++) {
            for(int j = i - 1; j >= 0; j--) {
                if((nums[i] % nums[j]) == 0) {
                    if(dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                    }
                }
            }
        }
        vector<int> output;
        int maxe = 0;
        for(int i : dp)
            maxe = max(maxe, i);
        
        for(int i = n - 1; i >= 0; i--) {
            if(dp[i] == maxe) {
                if(output.empty()) {
                    output.push_back(i);
                    maxe--;
                }
                else
                    if((nums[output.back()] % nums[i]) == 0) {
                        output.push_back(i);
                        maxe--;
                    }
            }
        }
        
        priority_queue<int> pq;
        for(int i : output) {
            pq.push(indices[nums[i]]);
        }
        for(int i = output.size() - 1; i >= 0; i--) {
            output[i] = temp[pq.top()];
            pq.pop();
        }
        return output;
    }
};