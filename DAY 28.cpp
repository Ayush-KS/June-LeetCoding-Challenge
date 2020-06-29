// Reconstruct Itinerary

class Solution {
public:
    vector<string> path;
    
    void hierholzer(unordered_map<string, priority_queue<string, vector<string>, greater<string> > >& mp, string curr) {
        while(!mp[curr].empty()) {
            string str = mp[curr].top();
            mp[curr].pop();
            hierholzer(mp, str);
        }
        path.push_back(curr);
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        unordered_map<string, priority_queue<string, vector<string>, greater<string> > > mp;
        
        for(vector<string> v : tickets) {
            mp[v[0]].push(v[1]);
        }
        
        hierholzer(mp, "JFK");
        reverse(path.begin(), path.end());
        return path;
    }
};