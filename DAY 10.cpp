// Search Insert Position

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.empty())
            return 0;
        int lo = 0, hi = nums.size();
        
        while(lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if(nums[mid] >= target) 
                hi = mid;
              else 
                lo = mid + 1;
        }
        return lo;
    }
};