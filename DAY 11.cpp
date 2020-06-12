// Sort Colors

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int zero, one, two;
        zero = one = 0;
        two = n - 1;
        
        while(one <= two) {
            if(nums[one] == 0) {
                swap(nums[zero], nums[one]);
                one++;
                zero++;
            } else if(nums[one] == 2) {
                swap(nums[one], nums[two]);
                two--;
            } else {
                one++;
            }
        }
    }
};