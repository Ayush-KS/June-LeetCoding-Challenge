// Single Number II

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int arr[32] = {0};
        for(int n : nums) {
            for(int i = 0; i < 32; i++) {
                arr[i] += (1 & (n >> i));
            }
        }
        
        int ans = 0;
        for(int i = 0; i < 32; i++) {
            if(arr[i] % 3) {
                ans |= (1 << i);
            }
        }
        return ans;
    }
};