// Queue Reconstruction by Height

#define pair pair<int, int>

static bool comp(const pair& x, const pair& y) {
    if (x.first == y.first)
        return x.second < y.second;

    return x.first > y.first;
}

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<pair> ppl;
        for(vector<int> v : people) {
            ppl.push_back({v[0], v[1]});
        }
        
        sort(ppl.begin(), ppl.end(), comp);
        
        stack<pair> st;
        
        
        for(pair p : ppl) {
            int s = p.second;
            stack<pair> temp;
            while(s--) {
                temp.push(st.top());
                st.pop();
            }
            st.push(p);
            while(!temp.empty()) {
                st.push(temp.top());
                temp.pop();
            }
        }
        int i = 0;
        
        while(!st.empty()) {
            people[i][0] = st.top().first;
            people[i++][1] = st.top().second;
            st.pop();
        }
        return people;
    }
};