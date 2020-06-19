// H-Index II

class Solution {
public:
    int hIndex(vector<int>& cit) {
        int n = cit.size();
        int lo = 0;
        int hi = cit.size() - 1;
        
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            
            if(cit[mid] == n - mid) {
                return n - mid;
            } else if(cit[mid] > n - mid) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return n - lo;
    }
};