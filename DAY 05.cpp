// Random Pick with Weight

class Solution {
public:
    vector<double> prob;

    Solution(vector<int>& w) {
        discrete_distribution<> d(w.begin(), w.end());
        prob = d.probabilities();
        for(int i = 1; i < prob.size(); i++) {
            prob[i] += prob[i - 1];
        }
    }
    
    int pickIndex() {
        double p = (double)rand() / RAND_MAX;
        
        int lo = 0, hi = prob.size() - 1;
        
        while(lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if(prob[mid] < p) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return lo;
    }
};
